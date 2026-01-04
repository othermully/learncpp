# 5.1 - Constant Variables

## Intro to constants
- Constants are values that may not be changed during a programs execution
- C++ supports two kinds of constants
    - **Named constants** - Associated with an identifier (Symbolic constants)
    -**Literal constants** - Not associated with an identifier

## Types of named constants
- Constant variables (most common)
- Object-like macros with substitution text
- Enumerated constants

## Constant variables
- Declaring a const variable
```
const double gravity { 9.8 }; // preferred use of const before type
```

- The type of an object includes the const qualifier
`const double gravity { 9.8 };` is type `const double`

### Const variables must be intialized
```
int main(){
    const double gravity { 9.8 }; // error: const vars must be initialized
    gravity = 9.9; // error: const vars can not be changed

    return 0;
}
```

- Note that const variables can be initialized from other variables (including non-const ones)

```
std::cout << "Enter your age: ";
int age{};
std::cin >> age;

const int constAge { age }; // initialize const var using non-const value;

age = 5; // ok: age is a non-const, so we can change its value
constAge = 6; // error: constAge is a const, so we cannot change its value
```

## Const function parameters
- Function parameter can be made constants via the `const` keyword
- Best practice is to not use `const` for value parameters

## Const return values
- A functions return value may also be made const
- Best practice is to not use `const` when returning a value
- Little point in returning const objects by value, because they are temp copies that will be destoyed anyway.
- Returning a const value can also impede certain kinds of compiler optimizations, resulting in lower performance

## Why variables should be made constant
- If a variable can be made constant, it should be.
    - It reduces the chance of bugs - Ensuring the value can't be changed
    - More optimization opportunities - compiler can assume the value wont change
    - Reduces overall complexity of our programs - We know a const can't have its value changed, so we don't have to worry about if its changing, or whether the new value is correct
    - Less moving parts, constant variables aren't moving parts
- Best practice is to make variables constant whenever possible, excpetion cases include by-value function params and by-value return types.

## Object-like macros with substition text
`#define MY_NAME "Alex"`

- When the preprocessor processes the file containing this, it will replace `MY_NAME` with `"Alex"`.
- Note that `MY_NAME` is a name, and the substitution text is a constant value, so that object-like macros with substitution text are also named constants.

## Prefer constant variables to preprocessor macros
- macros don't follow C++ scoping rules.
- Once a macro is #defined, all subsequents of the macros name in the current file will be replaced. If that name is used elsewhere, you'll get a macro substitution where you didn't want it.
```
#include <iostream>

void someFcn{
// Even though gravity is defined inside this function
// the preprocessor will replace all subsequent occurences of gravity in the rest of the file

#define gravity 9.8
}

void printGravity(double gravity) // including this one, causing a compilation error
{
    std::cout << "gravity: " << gravity << '\n';
}

int main(){
    printGravity(3.71);

    return 0;
}
```

- Best practive is to prefer constant variables over object-like macros with substitution text

## Nomenclature: type qualifiers
- A **type qualifier** (sometimes called a qualifier for short) is a keyword that is applied to a type that modifies how that type behaves. The `const` used to declare a constant variable is called a **const type qualifier** 
- As of C++23, C++ only has two type of qualifiers: `const` and `volatile`

