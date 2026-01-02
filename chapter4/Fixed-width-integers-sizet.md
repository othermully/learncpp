# 4.6 - Fixed-width integers and size_t

- C++ only guarantees that integer variables will have a minimum size, but they could be larger depending on the target system

- If you assume int is 32-bits because thats more likely, then your program will misbehave on architectures where int is actually 16-bits
- Instead, if you assume int is only 16-bits to ensure your program will behave on all architechtures, then the range of values you can safely store in an int is significantly limited. And on systems where int is actually 32-bits, you're not making use of half the memory allocated per int

## Why isn't the size of integer types fixed?
- Early days of C - Opted to intentionally leave the size of an int open so that the compiler implementers could pick a size for int that performs best on the target computer architecture


## Fixed-width integers
- C++11 provides an alternative set of integer types that are guaranteed to be the same size on any architecture
- Fixed-wdith ints are defined in the <cstdint> header

std::int8_t - These 8-bit ones behave as chars (most systems)
std::uint8_t
...
std::int64_t
std::uint64_t

- Fixed-width ints are not guaranteed to be defined on all architectures.
- Second, if you use a fixed-width integer, it may be slower than a wider type on some architectures. Since some CPUs are designed to process larger sizes quicker. For example if you need an int guaranteed to be 32-bits you use a std::int32_t, but the CPU might be faster at processing 64-bit integers.

- Fixed-width integers don't define new types, they are just aliases for existing types with the desired size, e.g where 'int' is 32-bits, std::int32_t will be an alias for int, on a system where 'int' is 16-bits, std::int32_t will be an alias for 'long' instead

## Best practice
- Prefer 'int' when the size of the integer doesn't matter
- Prefer std::int#_t when storing a quantity that needs a guranteed range
- Prefer std::uint#_t when doing bit manipulation or well-defined wrap around behaviour is required.


## size_t
- Use the <cstddef> header
- size_t is a type, returned by the sizeof operator 
- You can define like: std::size_t s { sizeof(x) };
