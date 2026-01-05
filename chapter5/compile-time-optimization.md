# 5.4 - The as-if rule and compile-time optimization

## Intro to optimization
- A profiler can measure how long various parts of the program are taking to run, allowing us to optimize the program by hand

- Other kinds of optimization can be performed automatically, a program that does this is called a **optimizer**. These typically work at a low-level looking for ways to improve statements or expressions by rewriting, reordering or eliminating them.

- Modern compilers are optimizing compilers, the optimizations they perform do not modify your source code.
    - Optimization might not be enabled by default
    - You might need to specify optimization flags

## Compile-time evaluation
- Modern C++ compilers are capable of fully or partially evaluating certain expressins at **compile-time** rather than at runtime. This is called **compile-time evaluation**

## Constant folding
- This is where the compiler will replace expressions that have literal operands with the result of the expression, e.g.:

```
//int x { 3 + 4 }; //
int x { 7 };
std::cout << x;
```

- This program produces the same output (`7`) as the prior version, but the executable no longer needs to spend CPU cycles calculating `3 + 4` at runtime

## Constant propagation
```
int main(){
    int x { 7 };
    std::cout << x << '\n';

    return 0;
}
```
- When `x` is initialized, the value `7` will be stored in the memory allocated for `x`. Then on the next line, the program will go out to memory again to fetch the value `7` so it can be printed. This required two memory access operations

- **Constant propagation** is an optimization technique where the compiler replaces variables known to have constant values with their values. Therefore, the compiler will realize that `x` always has the constant value of `7`, and replace any use of the variale `x` with the value `7`

## Dead code elimination

- **Dead code elimination** is an optimization technique where the compiler removes code that may be executed but has no effect on the programs behaviour.

- Lets say you define and initialize variable `x` with value `7`, then you print out the literal 7 to the console. 
```
int x { 7 };
```
- Is never used, so this will be **optimized out**

## Constant variables are easier to optimize 
- Using const variables can help the compiler optimzie more effectively
- If you can tell the compiler that something is a constant value that will not change, then it needs to do less work to figure out where it can optimize certain areas of your code

## Optimization can make programs harder to debug

- Some variables, expressions, statements and functions may be rearranged, modified, replaced, or removed entirely. Such changes can make it hard to debug a program

- To help minimize such issues, debug builds will typically leave optimizations turned off, so that the compiled code will be closer to the source code.

## Compile-time constants vs runtime constants

- A **compile-time constant** is a constant whose value is known at compile-time
    - Literals
    - Constant objects whose intializers are compile-time constants

- A **runtime constant** is a constant whose value is determined in a runtime context.
    - Constant function parameters
    - Constant objects whose initializers are non-constants or runtime constants

