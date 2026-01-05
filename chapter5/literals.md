# 5.2 - Literals

Literals are values that are inserted directly into the code

**LITERALS ARE VALUES NOT OBJECTS**
```
return 5; // 5 is a integer literal
bool myNameIsAlex { true }; // true is a boolean literal
double d { 3.4 }; // 3.4 is a double literal
std::cout << "Hello, world!"; // "Hello, world!" is a C-style string literal
```

- Literals are sometimes called **literal constants** because their meaning can not be redefined (`5` always mean the integral value 5).

## Types of a literal

Just like objects have a type, all literals have a type. The type of a literal is deduced from the literals value. For example, a literal that is a whole number is deduced to be a type of `int`

By default:
| Literal value | Examples    | Default literal type |
|---------------|-------------|----------------------|
| Integer value | 5, 0, -3    |    int               |
| boolean value | true,false  |    bool              |
| floating      | 1.2, 0.0    |  double (not float)  |
| character     | 'a', '\n'   |   char               |
| C string      | "Hello"     |   const char[5]      |  

## Literal suffixes
- If the default type of a literal is not as desired, you can change the type by adding a suffix.

- Prefer literal suffix L (upper case) or l (lower case)

### Integral literals
```
#include <iostream>

int main(){
    std::cout << 5; // 5 (no suffix) is type int (by default)
    std::cout << 5L; // 5L is type long
    std::cout << 5u; // 5u is type unsigned int

    return 0;
}
```

- In most cases, its fine to use non-suffixed `int` literals, even when initializing non-`int` types:
```
int a { 5 };            // ok: types match
unsigned int b { 6 };   // ok: compiler will convert int to unsigned int
long c { 7 };           // ok: compiler will convert int to long
```

## Floating point literals
- By default, floating point literals have a type of `double`. To make them `float` literals instead, the `f` (or `F`) suffix should be used:

- There is a difference between literal type and variable type

```
std::cout << 5.0;   // 5.0 (no suffix) is type double (by default)
std::cout << 5.0f   // 5.0f is type float
```
- New programmers are often confused about why the following causes a compiler warning:
```
float f { 4.1 }; // warning: 4.1 is a double literal, not a float literals
```

- Because `4.1` has no suffix, the literal has type `double` not `float`. When the compiler the type of a literal, it doesn't care what you're doing with the literal (e.g. in this case, using it to initialize a `float` variable). Since the type of literal (`double`) doesn't match the type of the variable it is being used to initialize (`float`), the literal value must be converted to a `float` so it can then be used to initialize variable `f`. 
    - Convert `double` to `float` causes loss of precision

```
float f { 4.1f };   // use 'f' suffix so the literal is a float
double d { 4.1 };   // change var type to double so it matches literal type
```

## String literals
A **string** is a collection of sequential characters used to represent text (such as names, words, and sentences)

`"Hello, world!"` is a string literal. String literals are placed between double quotes to identify them as string (as opposed to char literals, which are placed in single quotes).

- Modern programming languages include a fundamental string data type.
- Strings are not a fundamental type in C++.
- C++ has **C-style** strings, which are hard to work with.

There are two non-obvious things worth knowing about the C-style string literals.
- A C-style string literlas have an implicit null terminator. 
- `"hello"` has 6 characters.
    - `h`, `e`, `l`, `l`, `o` and `\0`
    - `\0` is a **null terminator** 
    - This would be considered a **null terminated string**
- `"Hello, world!"` has type `const char[14]` rather than `const char[13]`
    - Because the hidden null terminator 

Unlike most other literals (which are values, not objects), C-style string literals are const objects that are created at the start of the program and are guaranteed to exist for the entirety of the program.

Unlike C-style string literals, `std::string` and `std::string_view` literals create temporary objects which must be used immediately, as they are destroyed at the end of the full expression in which they are created

## Magic Numbers
- A **magic number** is a literal (usually a number) that either has an unclear meaning or may need to be changed later.

```
const int maxStudentsPerSchool{ numClassrooms * 30 }
setMax(30);
```

What do the literals `30` mean in these contexts?
