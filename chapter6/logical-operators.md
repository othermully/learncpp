# 6.8 - Logical Operators
Relational (comparison) operators can be used to test whether a particular condition is true or false, they can only test one condition at a time.

Often we need to know whether multiple conditions are true simultaneously. 

C++ has 3 logical operators:
- Logical NOT: !    (e.g. !x)
- Logical AND: &&   (e.g. x && y)
- Logical OR: ||    (e.g. x || y)

## Logical NOT

**Note**: logical NOT has high level of precedence, the expression `! x > y` actually evaluates to `(!x) > y)`. Since x is 5, !x evaluates to 0, and `0 > y` is false.

If logical NOT's operands evaluates to true, logical NOT evaluates to false. If logical operand evaluates to false, logical NOT evaluates to true. In other words, logical NOT flips a boolean value from true to false, and vice-versa.

```
int x{ 5 };
int y{ 7 };

if (!x > y)
    std::cout << x << " is not greater than " << y;
else
    std::cout << x << " is greater than " << y;
```

This prints:
`5 is greater than 7`

Wrap the expression in parenthesis, e.g `!(x > y)`

**Best practice**
- If logical NOT is intended to operate on the result of other operators, the other operators and their operands need to be enclosed in parentheses

## Logical OR

- `||` : `value == 0 || value == 1`

The logical OR operator is used to test whether either of two conditions is true. If the left operand evaluates to true, or the right operands evaluates to true, or both are true, then the OR operator returns true. Otherwise it will return false

## Logical AND
The AND operator is used to test whether both operands are true. If both operands are true, logical AND returns true. Otherwise it returns false.

- You can string together many logical AND statments as well
`value > 10 && value < 20 && value != 16)`

## Short circuit evaluation
In order for logical AND to return true, both operands must evaluate to true. If the left operand evaluates to false, logical AND knows it must return false regardlesss of the whether the right operand evaluates to true or false. In this case, the logical AND operator will go ahead and return false immediately without even evaluating the right operand!

This is know as **short circuit evaluation** and is done more optimization purposes.

Similarly, if the left operand for logical OR is true, then the entire OR condition has to evaluate to true, and the right operand won't be evaluated

Consider the following snippet:
```
if (x == 1 && ++y == 2)
    // do something
```

If `x` does not equal 1, the whole condition must be false, so ++y never gets evaluated! Thusm y will only be incremented if `x` evaluates to 1

**Best practice** 
- When mixing logical AND and logical OR in a single expresssion, explicitly parenthesize each operation to ensure they evaluate how you intend.
