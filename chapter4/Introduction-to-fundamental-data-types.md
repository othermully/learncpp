# 4.1 - Introduction to fundamental data types

## Bits, bytes and memory addressing
- Smallest unit of memory is a binary digit (bit) which holds either 0 or 1
- Memory segments hold groups of bits (standard 8) called a byte
- C++ Typically works with "byte-sized" chunks
- Memory is organized into sequential units called memory addresses
- Addresses allow us to find and access contents of memory at a location

## Data types
- Types tell the compiler how to interprest the contents of memory
- Compiler and CPU handle encoding values into appropiate sequence of bits for that data type, which are then stored in memory.
- Int object with value 65 gets converted to 0100 0001 and stored in the memory assigned to the object

## Funamental data types
- C++ Comes with predefined data types:
    - float
    - double
    - long double
    - bool
    - char
    - wchar_t
    - char8_t (C++20)
    - char16_t (C++11)
    - char32_t (C++11)
    - short int
    - int
    - long int
    - long long int (C++11)
    - std::nullptr_t - null pointer
    - void - no type

### The _t suffix represent "type"
    

## Object sizes
- A single bit can hold 2 possible values
- An object with n bits (where n is an integer) can hold 2^n unique values
- A byte sized object can hold 2^8 different values
- Thus, the size of an object puts a limit on the amount of unique values it can store.

### Fundamental data type sizes
- An object must occupy at least 1 byte (So that each object has a distinct memory address)

TYPE    MIN_SIZE     TYPICAL_SIZE
bool       1              1
char       1(exactly)     1 
wchar_t    1              2 or 4
char8_t    1              1
char16_t   2              2
char32_t   4              4
short      2              2
int        2              4
long       4              4 or 8
long long  8              8
float      4              4
double     8              8
long double 8             8,12 or 16 bytes
std::nullptr_t 4          4 or 8 bytes

- For max portability, you shouldn't assume that objects are larger than specified minimum size
