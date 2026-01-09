# 6.x Chapter 6 summary and quiz

## Quick Review

Alwayse use parentheses to disambiguate the precedence of operators if there is any question or opportunity for confusion.

The arithmetic operators all work like they do in normal math.

The increment and decrement operators can be used to easily increment or decrement numbers. Avoid the postfix version of these operators whenever possible

Beware of side effects, particularly when it comes to the order that function parameters are evaluated. Do not use a variable that has a side effect applied more than once in a given statement

The comma operator can compress multiple statements into one. Writing the statements separtely is usally better.

The **conditional operator** (`?:`) is a ternary operator (operator that takes 3 operands). Given a conditional operation of the form `c ? x : y`, if conditional `c` evaluates to `true` then `x` will be evaluated, otherswise `y` will be evaluated. The conditional operator typically needs to be parenthesized as follows:
- Parenthesize the entire conditional operator when used in a compound expression
- For readability, parenthesize the condition if it contains any operators (other than the function call operator)

Relational operators can be used to compare floating point numbers. Beware using equality and inequality on floating point nubmers.

Logical operators allow us to form compound conditional statements.
