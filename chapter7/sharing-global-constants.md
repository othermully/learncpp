# 7.10 - Sharing global constants across multiple files (using inline variables)

Sometimes you need to propagate a global constant to multiple files, and if you declare them once in a central place, its easier to change them if needed.

Here are some ways of doing so:

## Global constants as internal variables
- Create header file to hold these constants
- Inside header, define namespace
- Add all constants inside the namespace (make sure theyre constexpr)
- #include the header file wherever you need it

constants.h
```
#ifndef CONSTANTS_H
#define CONSTANT_H

// Define your own namespace to hold constants
namespace constants {
    constexpr double pi { 3.14159 };
    constexpr double avogadro { 6.0221413e23 };
    constexpr double myGravity { 9.2 }; 

}
#endif
```
main.cpp
```
#include "constants.h" // include a copy of each constant in this file

constants::pi 
```

While this method is simple and fine for smaller programs, every time constants.h gets #included into a different code file, each of these variables is copied into the including code file. Therefore, if constans get included into 20 different code files, each of those variables are copied 20 times.
    - Changing a single constant value would require recompiling every file that includes the constant
    - If the constans are large in size, this can use alot of memory

## Global constants as external variables
This allows us to have a single variable (initialized once) that is shared accross all file. In this method, we'll define the constants in a .cpp file (to ensure definitions only exist in one place) and put forward declarations in the header

The symbolic constants will get instantiated only once (inside of constants.cpp) instead of in each code file where constants.h is #included, and all uses of these constants will be linked to the version instantiated in constant.cpp. Any changes made to constants.cpp will require recompiling only constants.cpp

### Downsides:
Because only the variable definitions are constexpr, these constants are constant expressions only within the file they are actually defined in. In other files, the compiler will only see the forward declaration, which doesn't define a constexpr value (and must be resolved by the linker),

### Key insight:
In order for variables to be usable in compile-time contexts, such as array sizes, the compiler has to see the variables definition (not just a forward declaration)

## Global constants as inline variables (Recommended C++17)

Inline variables are variables that can have more than one defintion, so long as those definitions are identical. By making out constexpr variables inline, we can define them in a header file and then #include them into any .cpp file that requires them. This avoids both ODR violations and the downside of duplicated variables.

These variables will only be instantiated once and shared across code file
- Retains the downside of requiring every file that includes the constants header be recompiled if any changes.
- However, only one copy of each variable is required.
- Only works in C++17 onward


