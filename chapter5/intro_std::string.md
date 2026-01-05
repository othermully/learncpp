# 5.7 - Introduction to std::string

- `std::string` and `std::stringview` aren't fundamental data types
- lives in the `<string>` header

- Create objects of type `std::string` just like other objects:
```
std::string name {}; // empty string
```

- Just like normal variables, you can initialize or assign values to std::string objects as you would expect:
```
std::string name { "Alex" }; // Initialize name with string literal "Alex"

name = "John";               // change name to "John"
```
## String output with `std::cout`

```
std::string name { "Alex" };
std::cout << "My name is: " << name << '\n';
```

- If a `std::string` doesn't have enough memory to store a string, it will request additional memory (at runtime) using a form of memory allocation known as dynamic memory allocation.
    - This makes it flexible, but also slow.

## String input with `std::cin`
- `operator>>` only returns characters up to the first whitespace it encounters. Any other characters left inside `std::cin`, waiting for the next extraction.

- So when we use `operator>>` to extract input into variable `name`, only anything before a whitespace was extracted, leaving the remaning charcters inside `std::cin`.

## Use `std::getline()` to input text
- `std::getline()` requires two arguments:
    - The first is `std::cin`
    - The second in the string variable

```
#include <iostream>
#include <string>

int main(){

    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your favorite color: ";
    std::string color{};
    std::getline(std::cin >> std:ws, color); 

    std::cout << "Name: " << name << " color: " << color << '\n';

    return 0;
}
```

## `std::ws`

- The `std::ws` output manipulator tell `std::cin` to ignore any leading whitespace before extraction. 

## Best practice

- If using `std::getline()` to read strings, use `std::cin >> std::ws` input manipulator to ignore leading whitespace. This needs to be done for each std::getline() call, as `std::ws` is not preseved across calls.

## The length of a `std::string`
```
std::string name { "Alex" };
std::cout << name.length();
```
- `.length()` is a member function  
- Returns an unsigned integral value (most likely of type `size_t`)
- If you want to assign the length to an `int` variable, you should `static_cast` it to avoid compiler warnings about signed/unsigned conversions.

```
int length { static_cast<int>(name.length()) };
```

## Initializing a `std::string` is expensive
- Whenever a std::string is initialized, a copy of the string used to initialize it is made.

## Do not pass `std::string` by value
- When `std::string` is passed to a function by value, the `std::string` function parameter must be instantiated and initialized with the argument. This results in an expensive copy

## Best Practice
- Do not pass `std::string` by value, as it makes an expensive copy

## Returning a `std::string`
- It is okay to return a `std::string` by value when the expresssion of the return statement resolves to any of the following:
    - A local variable of type `std::string`
    - A `std::string` that has been returned by value from another function call or operator.
    - A `std::string` temporary that is created as part of the return statement.

- In most other cases, prefer to avoid returning a `std::string` by value, as doing so will make an expensive copy.

## Literals for `std::string`
- Double-quoted string literals (like "Hello, world!") are C-style string by default (and thus, have a strange type). 

- We can create string literals with the type `std::string` by using a `s` suffix after the double-quoted string literal. The `s` must be lowercase

```
using namespace std::string_literals; // easy access to the s suffix
std::cout << "goo\n"s;                // s suffix is a std::string literal
```

## Constexpr strings
- If you need constexpr strings, use `std::string_view` instead



