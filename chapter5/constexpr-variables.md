# 5.6 - Constexpr variables

- The use of `const` does not make it immediately clear whether the variable is usable in a constant expression or not. In some cases, we can figure it out fairly easily:

- **If the compiler knows the value at compile time, it doesn't need memory**
    - Stored in CPU register (Things CPU is holding in its hands)
    - Extremely fast read/writes
    - Very small, accessed 1 CPU cycle (or close)

```
int a { 5 };         // not const at all
const int b { a };   // clearly not a constant
const int c { 5 };   // clearly a constant
```

- In other cases it can be difficult:

```
const int d { someVar };    // not obvious whether d is useable in a constant expression or nt

const int e { getValue() }; // not obvious
```

- In the example above, `d` and `e` may or may not be usable in a constant expression, depending on how `someVar` and `getValue()` are defined.
    - Use of `const` does not provide a way to inform the compiler that we require a variable that is usable in a constant expression (and that it should halt complation if it isn't). Instead we just silently create a variable that can only be used in runtime expressions.
    - the use of `const` to create compile-time constant vars does not extend to non-integral variables.

## The `constexpr` keyword
- `constexpr` variables are always a compile-time constant
- Must be initialized with a constant expression, otherwise a compilation error will result.

```
constexpr double gravity { 9.8 }; // ok: 9.8 is a constant expression
constexpr int sum { 4 + 5 };      // ok: 4 + 5 is a constant expression
constexpr int something { sum };  // ok: sum is a constant expression

std::cout << "Enter your age: ";
int age{};
std::cin >> age;

constexpr int myAge { age };      // compile error: age is not a constant expr
```

## const vs constexpr for variables
- `const` = value cannot be changed after init, value of the initializer may be known at compile-time or runtime. The const object can be evaluated at runtime
- `constexpr` = the object can be used in a constant expression. The value of the initializer must be known at compile-time. The constexpr object can be evaluated at runtime or compile-time.

Constexpr variables are implicitly const. Const variables are not implicitly constexpr

- `constexpr int` has type of `const int`

## Best practice
- Any constant variable whose initializer is a constant expresssion should be declared as `constexpr`

- Any constant variable whose initialzier is not a constant expression (making it a runtime constant) should be declared as `const`

## Intro to constexpr functions
- A `constexpr function` is a function that can be called in a constant expression.
- To make a constexpr function, the `constexpr` keyword is placed in the function declaration before the return type:

```
constexpr int cmax(int x, int y){
    if (x > y)
        return x;
    else
        return y;
}

int main(){

int m4 { cmax(5,6) };           // ok: may eval at compile-time or runtime
constexpr int m5 { cmax(5,6) }; // ok: must eval at compile-time
}
```
