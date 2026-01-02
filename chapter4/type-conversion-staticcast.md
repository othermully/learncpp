# 4.12 - Intro to type conversion and static cast

- Consider the program:

```
void print(double x){ // Prints takes a double parameter
    std::cout << x << '\n';
}

int main(){
    print(5); // What happens when we pass an int value?
    return 0;
}
```

In the above example, the print() function takes in a double, but the caller is passing in the int type value of 5.
- C++ will allow us to convert fundamental types, this is called type-conversion

- In this case, the int argument `5` will be converted to a double value `5.0`, then copied into the parameter `x`.

- The `print()` function will print this value, resulting in an output of `5`
    - By default, floating point values whose decimal part is 0 print without the decimal places (e.g. `5.0` prints as `5`)

- When the compiler does type conversion on our behalf without us explicitly asking, we call this **implicit type conversion**

## Type conversion of a value produces a new value
- The type conversion of a value to another type of value behaves much like a call to a function whose return thpe matches the target type of the conversion.
- The data to be converted is passed in as an argument, and the converted result is returned (in a temp object) to be used by the caller.

## Key insight
- Some type conversion (such as a `char` to an `int`) always preserve the value being converted, whereas others (such as `double` to `int`) may result in the value being changed during conversion. Unsafe implicit conversins will typically either generate a compiler warning, or (in the case of brace init) an error.

- This is one of the primary reasons brace initialization is the preferred init form. Brace initialization will ensure we don't try to initialize a variable with an initializer that will lose value when it is implicitly type converted:

```
int main(){
    double d { 5 }; // okay: int to double is safe
    int x { 5.5 }; // Error: double to int is not safe

    return 0;
}
```

## An introduction to explicit type conversion via the static_cast operator
- **Explicit type conversion** allow us to explicitly tell the compiler to convert a value from one type to another type, and that we take full responsibility for the result of that conversion.

- To perform an explicit type conversion, in most cases we'll use the `staic_cast` operator. The syntax looks like this:
```
static_cast<new_type>(expresssion)
```
- static_cast takes the value from an expression as input, and returns the value converted into the type specified by the `new_type` (e.g. int,bool,char,double).

### Key insight
- Whenever you see C++ syntax (excluding the preprocessor) that makes use of the angled brackets (<>), the thing between the brackets will most likely be a type. This is typically how C++ deals with code that needs a parameterized type.

```
void print(int x){
    std::cout << x << '\n';
}

int main(){
    print( static_cast<int>(5.5) ); // Explicitly convert double value 5.5 to an int

    return 0;
}
```

## Using static_cast to convert char to int
```
#include <iostream>
int main(){
    char ch{ 97 }; // 97 is ASCII for 'a'
    std::cout << ch << " has value << static_cast<int>(ch) << '\n';

    return 0;
}
```

- This prints:
```
a has value 97
```

## Sign conversion using static_cast
- Signed integral values can be converted to unsigned integral values, and vice-versa, using a static cast.

- If the value being converted can be represented in the destination type, the converted value will remain unchanged(only the type will change). For example:

```
int main(){
    unsigned int u1 { 5 };
    // Convert value of u1 to a signed int
    int s1 { static_cast<int>(u1) };
    std::cout << s1 << '\n'; // prints 5

    int s2 { 5 };
    // Convert signed value of s2 to an unsigned int
    unsigned int u2 { static_cast<unsigned int>(s2) };

    std::cout << u2 << '\n'; // Prints 5

    return 0;
}
```

