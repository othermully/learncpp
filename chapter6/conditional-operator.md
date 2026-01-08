# 6.6 - The conditional operator

| Operator  | Symbol    | Form  | Meaning                               |
|-----------|-----------|-------|---------------------------------------|
|Conditional| ?:        |c ? x:y| If c is true, eval `x`, if!, eval `y` |

The **conditional operator** (`?:`) is a ternary operator ( an operator that takes 3 operands). 

The `?:` operator provides a shorthand method for doing particular type of is-else statement.

```
if (x > y)
    max = x;
else
    max = y;
```

Can also be written as:

```
max = ((x > y) ? x : y);
```

## Parenthesizing the conditional operator
Because C++ prioritizes the evaluation of most operators above the evaluation of the conditional operator, it's quite easy to write expressions using the conditional operator that don't evaluate as expected

**Best practice**
- Parenthesize the entire conditional operation (including operands) when used in a compound expression.

- For readability, consider parenthesizing the condition if it contains any operators (other than the function call operator)

## The type of expressions must match or be convertible
- The type of the second and third operand must match
- The compiler must be able to find a way to convert one or both of the second and third operands to matching types. 

For example:
```
#include <iostream>

int main(){
    std::cout << (true ? 1 : 2) << '\n'; // okay: both operands have matching type of int

    std::cout << (true ? 1 : 2.2) << '\n'; // okay: int value 1 converted to double

    std::cout << (true ? -1 : 2u) << '\n'; // suprising result: -1 converted to unsigned int, results out of range

    return 0;
}
```
In general, its okay to mix operands with fundamental types (excluding signed and unsigned values), it either operand is not a fundamental type, its generally best to explicitly convert one or both operands to a matching type yourself so you know exactly what you'll get

## When to use the conditional operator?
- Intializing an object with one of two values
- Assigning one of two values to an object
- Passing one of two values to a function
- Returning one of two values from a function
- Printing one of two values

**Best Practice**
- Prefer to avoid the conditional operator in complicated expressions

