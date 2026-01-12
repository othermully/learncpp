# 7.6 - Internal Linkage
An indentifiers linkage determines whether other declarations of that name refer to the same object or not. local variables have `no linkage`

Global variables and function identifiers can either have `internal linkage` or `external linkage`.

An indentifer with **internal linkage** can be seen and used within a single translation unit (The ouput of the preprocessor), but it is not accessible from other translation units. This means that if two source files have identically named identifiers with internal linkage, those indentifers will be treated as independant.

## Global variables with internal linkage
Global variables with internal linkage are sometimes called **internal variables**

To make a non-constant global variable internal, we use the `static` keyword

```
#include <iostream>

static int g_x{}; // non-constant global variables have external linkage by default, but can be given internal linkage vifa the static keyword

const int g_y{ 1 }; // const globals have internal linkage by default
constexpr int g_z{ 2 }; // constexpr globals have internal linkage by default
```

a.cpp
```
[[maybe_unused]] constexpr int g_x { 2 }; // this internal g_x is only accessible within a.cpp
```

main.cpp
```
static int g_x { 3 }; // this separate internal g_x is only accessible within main.cpp
```

## Functions with internal linkage
Function identifiers also have linkage. Functions default to external linkage but can be set to internal linkage via the `static` keyword.

```
// This function is declared as static, and can now be used only within this file.
[[maybe_unused]] static int add(int x, int y){
    return x + y;
}
```

## Why bother giving internal linkage?
- There is an identifier we want to make sure insn't accessible to other file. This could be a global variable we don't want messed with, or a helper function we don't want to be called
- To be pedantic about avoiding naming collisions

**Best Practice**
- Give identifiers internal linkage when you have an explicit reason to disallow access from other files.

## Quick summary
```
static int g_x; // defines non-initialized internal global variable (0-init)
static int g_x{ 1 }; // defines initialized internal global var

const int g_y { 2 }; // defined intialized internal global const variable
constexpr int g_y { 3 }; // defines intialized internal global constexpr var

static int foo() {}; // defined internal function
```
