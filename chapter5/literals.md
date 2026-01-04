# 5.2 - Literals

Literals are values that are inserted directly into the code
```
return 5; // 5 is a integer literal
bool myNameIsAlex { true }; // true is a boolean literal
double d { 3.4 }; // 3.4 is a double literal
std::cout << "Hello, world!"; // "Hello, world!" is a C-style string literal
```

- Literals are sometimes called **literal constants** because their meaning can not be redefined (`5` always mean the integral value 5).

## Types of a literal

Just like objects have a type, all literals have a type. The type of a literal is deduced from the literals value. For example, a literal that is a whole number is deduced to be a type of `int`

By default:
| Literal value | Examples    | Default literal type |
|---------------|-------------|----------------------|
| Integer value | 5, 0, -3    |    int               |
| boolean value | true,false  |    bool              |
| floating      | 1.2, 0.0    |  double (not float)  |
| character     | 'a', '\n'   |   char               |
| C string      | "Hello"     |   const char[5]      |  

