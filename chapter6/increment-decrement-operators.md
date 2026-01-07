# 6.4 - Increment/Decrement operators, and side effects

- Incrementing (adding 1 to) and decrementing (subtracting 1 from) a variable are both so common that they have their own operators
    - `++x` : increment x, then return x
    - `--x` : decrement x, then return x
    - `x++` : Copy x, then increment x, then return the copy
    - `x--` : Copy x, then decrement x, then return the copy

```
int main(){

    int x { 5 };
    int y { ++x }; // x is incremented to 6, x is evaluated to the value 6, and 6 is assigned to y
}
```

```
int main(){
    int x { 5 };
    int y { x++ }; // x is incremented to 6, copy of original x is evaluated to the value 5, and 5 is assigned to y

    std::cout << x << ' ' << y << '\n';
    // This prints: 6 5
}
```

Examining the block above, First a temp copy of x is made that starts with the same value as x(5). Then the actual x is incremented from 5 to 6. Then the opy of x (which still has value 5) is returned and assigned to y. Then the temp copy is discarded

## When to use prefix vs postfix
In many cases, the prefix and postfix operators produce the same behaviour:
```
int x { 0 };
++x; // increments x to 1
x++; // increments x to 2
```

Best practice: Favor the prefix versions, as they are more performant and less likely to cause suprises

## Side effects can cause order of evaluation issues

```
#include <iostream>

int add(int x, int y){
    return x + y;
}

int main(){

    int x { 5 };
    int value { add(x, ++x) }; // UB: is this 5 + 6, or 6 + 6?
    // It depends on what order your compiler evaluates the function arguments in
    // Could be 11 or 12, depending on how it evaluates

    return 0;
}
```

## The sequencing of side effects
- ` x + ++x` is unspecified behaviour. When `x` is initialized to `1`, GCC evaluates this as `2 + 2`, and Clang evaluates it as `1 + 2`.

**WARNING**
- C++ does not define the order of evaluation for function arguments or the operands of operators

**WARNING**
- Don't use a variable that has a side effect applied to it more than once in agiven statement. If you do , the result may be undefined
