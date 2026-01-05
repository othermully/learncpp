# 5.5 - Constant Expresssions
- `const` - "I promise not to change it"
- `constexpr` - "The compiler knows it right now"

By default, expressions evaluate at runtime. And in some cases, they must do so:
```
std::cin >> x;
std::cout << 5 << '\n';
```
- Because input and output can't be performed at compile time, the expressions above are required to evaluate at runtime

- Under the as-if rule, the compiler may choose whether to evaluate certain expressions at runtime or compile time:

```
const double x { 1.2 };
const double y { 3.4 };
const double z { x + y }; // x + y may evaluate at runtime or compile-time
```

- Normally `x + y` would evaluate at rutime, but since the value of `x` and `y` are known at compile-time, the compiler may opt to perform compile-time evaluation isntead and initialize `z` with the compile-time calculated value `4.6`

- C++ requires an expression that can be evaluated at compile-time. For example, `constexpr` variables require an initialzier that can be evaluated at compile-time:

```
int main(){
    constexpr int x { expr }; // Because variable x is a constexpr, expr must be evaluated at compile-time
}
```

## The benefits of compile-time programming

- C++ provides ways to be explicit about what parts of code we want to execute at compile-time. The use of language features that result in compile-time evaluation is called **compile-time programming**
    - Performance: Compile-time evaluation makes our programs smaller and faster. The more code we can ensure is capable of evaluating at compile-time, the more performance benefit we'll see.
    - Versatility: We can always use such code in places that require a compile-time value. 
    - Predictability: We can have the compiler halt compilation if it determines that code cannot be executed at compile-time (rather than silently opting to have that code evaluate at runtime instead). This allows us to ensure a section of code we really want to execute at compile-time will.
    - Quality: We can tell the compiler detect certain kinds of programming errors at compile-time, and halt the build if it encounters them. Better than trying to detect and handle those same errors at runtime.
    - Quality: UB is not allowed at compile-time. If we do something that causes UB at compile-time, the compiler should halt the build and ask us to fix it.

- To summaraize, compile-time evaluation allows us to write programs that are both more performant and of higher quality (more secure and less buggy). So while compile-time evaluatin does add some complexity to the language, the benefits can be substantial.

- The following C++ features are the most foundational to compile-time programming:
    - Constexpr variables
    - Constexpr functions
    - Templates
    - static_assert
- All of these features have one thing in common: They make use of the constant expressions.

## Constant Expressions
- An expressin that must be evaluated at compile-time, along with rules that determine how the compiler should handle these expressions.
- A **constant expression** is a non-empty sequence of literals, constant variables, operators, and function calls. All of which must be evaluated at compile-time
- In a constant expression, each part of the expression must be evaluatable at compile-time.

An expression that is not a constant expression is often called a non-constant expression, and may informally be called a **runtime expression** (as such expressions typically evaluate at runtime).

## What can be in a constant expresssion

- Don't need to remember most of this, if a constant expression is required somewhere and you do not provide one, the compiler will happily point out your mistake, and you can fix it at that point

Most commonly, constant expressions contain the following:
- Literals 
- Most operators with constant expression operands (`3 + 4`, `2 * sizeof(int)`)
- Const integral variables with a constant expression initializer (e.g `const int x { 5 };`) - `constexpr` variables are preferred
- Constexpr variables
- Constexpr function calls with constant expression arguments

## Examples of constant and non-constant expressions

```
#include <iostream>

int getNumber(){
    std::cout << "Enter a number: ";
    int y {};
    std::cin >> y; // can only execute at runtime

    return y; // This return expression is a runtime expression
}

// The return value of a non-constexpr function is a runtime expression
// even when the return expression is a constant expression

int five(){
    return 5; // This return expression is a constant expression
}

int main(){
    // Literals can be used in constant expressions
    5;                  // constant expression
    1.2;                // constant expression
    "Hello, world!";    // constant expression

    // Most operators that have constant expresssion operands can be used in constant expressions
    5 + 6;              // constant expression
    1.2 * 3.4;          // constant expression
    sizeof(int) + 1     // constant expression (sizeof can be determined at compile time)

    // The return values of non-constexpr functions can only be used in runtime expressions

    getNumber();        // runtime expression
    five();             // runtime expresssion (even though the return expression is a constant expression)

    std::cout << 5;     // runtime expression (std::cout isn't a constant expression operand)

    return 0;
}
```

- The compiler is only required to evaluate constant expressions at compile-time in contexts that **require** a constant expression. It may or may not do so in other cases.
