# 5.8 - Intro to std::string_view

- `.remove_preix(#)`
- `.remove_suffix(#)`

Consider the following program:
```
int main(){
    int x { 5 }; // x makes a copy of its initializer
    std::cout << x << '\n';

    return 0;
}
```

When the definition for `x` is executed, the initialization value `5` is copied into the memory allocated for variable `int x`. For fundamental types, initializing and copying a variable is fast.

Now consider this similar program:
```
int main(){
    std::string s { "Hello, world!" };
    // s makes a copy of its initializer
    std::cout << s << '\n';

    return 0;
}
```
When `s` is initialized, the C-style string literal `"Hello, world!"` is copied into memory allocated for `std::string s`. Unlike fundamental types, initializing and copying a `std::string` is slow.

## std::string_view
- To address the issue with `std::string` being expensive to initialize (or copy), C++17 introduced `std::string_view` (which lives in the <string_view> header).
- `std::string_view` provides read-only access to an existing string without making a copy

```
void printSV(std::string_view str){
// now a std::string_view
    std::cout << str << '\n';
}

int main(){
    std::string_view s { "Hello, world!" }; // now a std::string_view
    printSV(s);

    return 0;
}
```

- This allows us to access "Hello, world!" through `str`, again without making a copy of the string

Best practice:
- Prefer `std::string_view` over `std::string` when you need a read-only string, especially for function params.

## `std::string_view` can be initialized with many different types of string
- a `std::string_view` object can be initialized with a C-style string, a `std::string` or another `std::string_view`
- Both a C-Style string and a `std::string` will implicity convert to a `std::string_view`. Therefore a `std::string_view` parameter will accept arguments of type C-style string, a `std::string` or `std::string_view`
- `std::string_view` will not implicitly convert to a `std::string`
    - Use static_cast if you need to do this

## Assignment changes what the `std::string_view` is viewing
- Assigning a new string to `std::string_view` causes the `std::string_view` to view the new string, it does not modify the prior string being viewed in any way.

## Literals for `std::string_view`
- Double-quoted string literals are C-style string literals by default.
- We can create string literals with the type `std::string_view` by using a `sv` suffix after the double-quoted string literal.

```
using namespace std::string_literals;
using namespace std::string_view_literals;

std::cout << "goo\n"s;  // the s suffix is a std::string literal
std::cout << "moo\n"sv; // the sv suffix is a std::string_view literal
```

- Its fine to initialize a `std::string_view` object with a C-style string literal (you don't need to initialize it with a `std::string_view` literal)

## constexpr `std::string_view`
- Unlike `std::string`, `std::string_view` has full support for constexpr
- `constexpr std::string_view` is the preferred choice when string symbolic constants are needed.

## A quick guide on when to use `std::string` vs `std::string_view`

### Variables
Use a `std::string` when:
- You need a string that you can modify
- You need to store user-inputted text.
- You need to store the return value of a function that returns a `std::string`

Use a `std::string_view` variable when:
- You need read-ony access to part or all of a string that already exists elsewhere and will not be modified or destroyed before use of the `std::string_view` is complete
- You need a symbolic constant for a C-Style string.
- You need to continue viewing the return value of a function that returns a C-style string or a non-dangling `std::string_view`

### Function parameters
Use a `std::string` function parameter when:
- The function needs to modify the string passed in as an argument without affecting the caller. This is rare.
- You are using language standard C++14 or older and aren't comfortable using references yet.

Uses a `std::string_view` function parameter when:
- The function needs a read-only string.
- The function needs to work with non-null-terminiated string.

### Return types
Use a `std::string` return type when:
- The return value is a `std::string` local variable or function param.
- The return value is a function call or operator that returns a `std::string` by value.

Use a `std::string_view` return type when:
- The function returns a C-style string literal or local `std::string_view` that has been initialized with a C-Style string literal
- The function returns a `std::string_view` parameter.

## Insights
Things to remember about `std::string`:
- Intializing and copying `std::string` is expensive, so avoid this as much as possible.
- Avoid passing `std::string` by value, as this makes a copy
- If possible, avoid creating short-lived `std::string` objects.
- Modifying a `std::string` will invalidate any views to that string
- It is okay to return a local `std::string` by value

This to remember about `std::string_view`
- `std::string_view` is typically used for passing string function parameters adn returning string literals.
- Because C-Style string literals exists for the entire program, it is always okay to set a `std::string_view` to a C-style string literal
- When a string is destroyed, all views to that string are invalidated
- Using an invalidated view (other than using assignment to revalidate the view) will cause undefined behaviour
- `std::string_view` may or may not be null-terminated
