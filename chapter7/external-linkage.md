# 7.7 - External linkage and variable forward declarations
An identifier with **external linkage** can be seen and used both from the file in which it is defined, and from other code files (via forward declaration). In this sense, identifiers with external linage are truly "global" in that they can be used anywhere in your program.
- External linkage means the identifiers are visible to the linker
    - Connect an identifer used in one translation unit with the appropriate definition in another translation unit.

## Functions have external linkage by default
In order to call a function defined in another file, you must place a `forward declaration` for the function in any other files wishing to use the function. The forward declaration tells the compiler about the existence of the function, and the linker connects the function calls to the actual function definition

a.cpp
```
#include <iostream>
void sayHi() // this function has external linkage, and can be used and seen by other files
{

    std::cout << "Hi\n";
}
```
main.cpp
```
void sayHi(); // forward declaration for function sayHi

int main(){
    sayHi();

    return 0;
}
```

## Global variables with external linkage
Global variables with external linkage are sometimes called **external variables**. To make a global variable external (and thus accessible by other files), we can use the `extern` keyword to do so:
```
int g_x { 2 }; non-const globals are external by default

extern const int g_y { 3 }; // const globals can be defined as extern
extern constexpr int g_z { 3 }; // constexpr globals can be defined as extern
```

## Variable forward declarations via the extern keyword
To actually use an exteral global variable that has been defined in another file, you must also place a `forward declaration` for the global variable in any other files wishing to use the variable. For variables, creating forward declarations is also done via the `extern` keyword (with no initialization value).

```
extern int g_x; // this extern is a forward declaration of a var named g_x that is defined somewhere else
extern const int g_y;
```

a.cpp
```
int g_x { 2 }; // non-const globals have external linkage by default
extern const int g_y { 3 }; // this extern gives g_y external linkage
```

## Quick summary
```
// Global variable forward declarations (extern w/ no initializer):
extern int g_y;         // forward declaration for non-constant global variable
extern const int g_y;    // fowarward declaration for const global var
extern constexpr int g_y' // not allowed: compiler needs to know at compile-time

// External global variable definitions (no extern)
int g_x; // Zero-initialized by default (external by default)
int g_x { 1 }; // initialized global variable

// External const global variable definitions (extern w/ initializer)
extern const int g_x { 2 }; // initialized const external
extern constexpr int g_x { 3 }' // intialized constexpr external global var
```
