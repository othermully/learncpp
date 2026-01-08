# 6.5 - The comma operator
The **comma operator (,)** allows you to evaluate multiple expressions wherever a single expression is allowed. The comma operator evaluates the left operand, then the right operand, and then return the result of the right operand

```
int main(){
    int x{ 1 };
    int y{ 2 };

    std::cout << (++x, ++y) << '\n'; // increment x and y, evaluates to the right operand
    // which subsequently prints 3 to the console

    return 0;
}
```

Note the comma has the lowest precedence of all the operators, even lower than assignment. Because of this, the following two lines of code do different things

```
z = (a, b); // evaluate (a, b) first to get the result of b, then assign that value to variable z.

z = a, b; // evaluates as "(z = a), b", so z gets assigned the value of a, and b is evaluated and discarded.
```

This makes the comma operator somewhat dangerous to use.

In almost every case, a statement written using the comma operator would be better as separate statements. For example, the above code could be written as:
```
int main(){
    int x{ 1 };
    int y{ 2 };

    ++x;
    std::cout << ++y << '\n';

    return 0;
}
```

**Best practice** 
- Avoid using the comma operator, except within for loops

## Comma aas a separator
In C++, the comma symbol is often used as a separator, and these uses d not invoke the comma operator. Some examples of separator commas:
```
void foo(int x, int y); // Separator comma used to separate parameters in function declaration and definitions
```
