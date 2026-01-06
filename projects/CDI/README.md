# Project: Console Data Inspector & Converter
## High-level Description
Build a **menu-driven console application** that lets a user:
- Enter a numeric or character data
- Inspect properties of that data
- Convert it between types and numeral systems
- Display detailed information about sizes, ranges and interpretations

The program acts like a **learning diagnostic tool** for fundamental C++ data types

## Core Requirements
### Program Structure
Program Must:
- Be split into multiple `.cpp` and `.h` files
- Use atleast one namespace
- Use header guards
- Use forward declarations
- Have `main.cpp` focused mainly on program flow, not logic
    - `main.cpp`
    - `input.h / input.cpp`
    - `inspect.h / inspect.cpp`
    - `convert.h / convert.cpp`
    - `constants.h`

### Menu System
When the program starts:
- Display a menu using `std::cout`
- Ask the user to choose one option using `std::cin`

Menu options might include:
- Inspect an integer
- Inspect a floating-point number
- Inspect a character
- Convert between types
- Display system/type information

## Functional Requirements by Topic

### Fundamental Data Types

#### Integer Inspection

When the user enters an integer:
- Store it as a **signed integer**
- Display:
    - Its value
    - Whether its positive, negative or zero
    - Whether its even or odd
- Display its size in **bytes**
- Demonstrate why **unsigned** is avoided

Use:
- `int`
- `std::int32_t` or similar
- `size_t` for object sizes

#### Floating-Point Inspection

When the user enters a floating-point number:
- Accept scientific notation input
- Display:
    - Value
    - Whether its zero, pos, neg
    - Size in bytes
- Perform at least one **floating-point calculation**
- Show how precision behaves

Use:
- `double`
- Floating-point literals

#### Boolean Evaluation
- Use boolean values to store results of comparisons
- Print boolean results in a human-readable way (true/false meaning)

#### Character Inspection

When the user enters a character:
Display:
- The character itself
- Its integer value (using type conversion)
- Whether its a digit, letter or something else (simple comparisons)

Use:
- `char`
- `static_cast` for conversion to `int`

#### Type Conversion
Your program must:
- Convert between:
    - `char` -> `int`
    - `int` -> `double`
- Use `static_cast` explicitly
- Explain (via output text) why implicit conversion is avoided

#### Constants & Compile-Time concepts
**Constant Variables**
- Store values like:
    - Menu option numbers
    - Numeric base identifier
- Use `const` variables where values should not change

**Constant Expressions**
- Use `constexpr` for:
    - Fixed conversion factors
    - Known compile-time values
- Demonstrate values used in calculations

**As-If Rule**
- Include an explanation printed to the user
- Use compile-time constraints to show that the compiler can optimize (no benchmarking needed)

#### Numeral Systems
Your program must:
- Display integer values in:
    - Decimal 
    - Binary
    - Hexadecimal
- Accept integer literals internally using different numeral systems
- Explain (via output) what base each representation uses

#### Strings
`std::string`
Use `std::string` to:
    - Store user names
    - Store descriptive messages
    - Build output messages

`std::string_view`
Use `std::string_view` for:
    - Function parameters that only read text
    - Menu option labels
    - Messages that don't need ownership
Demonstrate:
    - Passing `std::string_view` to functions
    - Avoiding unnecessary copies

#### Program Design Contraints
You **must not** use:
    - Loops
    - Classes
    - Arrays or containers
    - Exceptions
    - Advanced STL algorithms
You **must** use:
    - If / else if / else chains
    - Clear function boundaries
    - Local scope properly
    - Well-named identifiers
    - Intialization of all variables
