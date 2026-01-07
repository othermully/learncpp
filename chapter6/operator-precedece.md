# 6.1 - Operator precedence

At compile time, the compiler must parse the expression and determine how operands are grouped with operators. This is done via the precedence and associativity rules.

At compile time or runtime, the operands are evaluated and operations executed produce a result

## Operator precedence
Operators with higher **precedence** level are grouped with operands first
- `4 + 2 * 3` will be grouped as `4 + (2 * 3)` - This should be obvious

- In a less obvious example `7 - 4 -1`:
    - The operators **associativity** tells the compiler whether to evaluate the operators (not the operands!) from left to right, or from right to left.
    - Subtraction has a precedence level 6, and the operators in precedence level 6 have an associativity of left to right.
    - So this expression is grouped left to right `(7 - 4) - 1`

Visit: `https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/` for the pref/assco reference table

## Parenthesization
- Just like in normal math, in C++ we can explicityly use parentheses to set the grouping of operands as we desire. Since () have one of the highest precedence levels, they evaluate before whatever is inside them.

- Instead of looking at the reference table each time, parenthesize everything except addition, subtraction, multiplication and division.
    - Best practice is to use parentheses to make it clear how a non-trivial compound expression should evaluate

- There is one additinal exception to the above best practice: Expressions that have a single assignment operator (and no comma operator) do not need to have the right operand of the assignment wrapped in parenthesis

```
x = (y + z + w);        // instead of this
x = y + z + w;          // it's okay to do this

x = ((y || z) && w);    // instead of this
x = (y || z) && w;      // it's okay to do this
```

- Best practice: Expressions with a single assignment operator do not need to have the right operand of the assignment wrapped in parenthesis

## Value computation of operations
**value computation** means the execution of operators in an expressin to produce a value.

## Evaluation of operands
The C++ standard (mostly) uses the term **evaluation** to refer to the evaluation of operands (not the evaluation of operators or expressions). For example, given expression `a + b`, `a` will be evaluated to produce some value, and `b` will be evaluated to produce some value. These values can then be used as operands to `operator+` for value computation
- Informally, we typically use the term "evaluates" to mean the evaluation of the entire expression (value computation), not just the operands of an expression.

Tip: GCC compiler evaluates function arguments in right-to-left order, whereas Clang compiler evaluates arguments in left-to-right order.
- Ensure that the expressions (or function calls) you write ar enot dependent on operand (or arugment) evaluatin order.


