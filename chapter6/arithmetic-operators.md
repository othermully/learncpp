# 6.2 - Arithmetic operators

## Unary arithmetic operators
There are two unary arithmetic operators, plus (+), and minus (-). As a reminder, the unary operators are operators that only take 1 operand
- if x = 5, -x is -5
- Don't confuse unary minus with binary subtraction.
    - x = 5 - -3; 
    - The first minus is the binary subtraction operator
    - The second one is the unary minus operator

## Binary arithmetic operators
- Addition: + , x + y
- Subtraction: -, x - y
- Multiplication: *, x * y
- Division: /, x / y
- Remainder: %, ox % y

## Integer and floating point divison
- If either or both operands are floating point, division operator performs floating point division, fraction is kept
- If both of the operands are integers, the division operator performs integer division, drops any fractions

## Using static_cast<> to do floating point divisoin with integers

```
int main(){
    constexpr int x{ 7 };
    constexpr int y{ 4 };

    std::cout << "int / int = " << x / y << '\n';
    std::cout << "double / int = " << static_cast<double>(x) / y << '\n';
    std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << '\n';

    return 0;
}
```

This produces result:
```
int / int = 1
double / int = 1.75
double / double = 1.75
```

## Don't divide by zero lol

## Arithmetic assignment operators

| Operator                | Symbol | Form   | Operation         |
|-------------------------|--------|--------|-------------------|
| Add assignment          | +=     | x += y | Add y to x        |
| Sub assignment          | -=     | x -= y | subtract y from x |
|Multiplication assignment| *=     | x *= y | multiply x by y   |
|Divison assignment       | /=     | x /= y | divide x by y     |
| Remainder assignment    | %=     | x %= y | remain of x/y in x|


Because writing statements such as `x = x + 4` is so common, C++ provides five arithmetic assignment operators for convenience. Instead of writing `x = x + 4`, you can write `x += 4`.


