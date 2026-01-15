# 7.9 - Inline functions and variables

- Historically the compiler didn't have the capability to determine whether inline expansion would be beneficial, or wasn't good at it. For this reason C++ provided the `inline` keyword which was originally intended to hint to the compiler that a function would (probably) benefit from inline expansion.

- Don't use the `inline` keyword to request inline expansion
    - Your compiler knows better than you

## The inline keyword, modernly
The inline keyword is typically used in header files, and is primarily a method to tell the compiler that multiple definitions of an identifier is allowed, aslong as it follows the primary requirements.

Inline functions have two primary requirements:
- The compiler needs to be able to see the full definition of an inline function in each translation unit where the function is used.
- The definition can occur after the point of use if a forward declaration is also provided, however the compiler will likely not be able to perform inline expansion until it has seen the definition
- Every definition for an inline function (with external linkage, which functions have by default) must be identidical, otherwise UB will occur.

**Best practice**
Avoid the use of the `inline` keyword unless you have a specific, compelling reason to do so (eg. you're defining those functions or variables in a header file)

## Why not make all function inline and defined in a header file?
Mainly because doing so can increase your compile times significantly

When a header containing an inline function is #included into a source file, that function definition will be compiled as part of that translation unit. An inline function #included into 6 translation units will have its definition compiled 6 times ( before the linker deduplicates the definitions)

