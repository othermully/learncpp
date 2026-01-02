# 4.x - Chapter 4 summary and quiz

## Chapter review
- Smallest unit of memory is a **binary digit** (bit)
- Smallest unit amount of memory that can be addressed (accessed) directly is called a **byte**
- Modern standard is that a byte equals 8 bits.

- A **data type** tells the compiler how to interpret the contents of memory in some meaningful way

- C++ comes with support for many fundamental data types:
    - floating point numbers
    - Integers
    - Boolean
    - Chars
    - Null Pointers
    - Void

- **Void** is used to indicate no type. Primarily used to indicate a function does not return a value

- Different types take different amounts of memory, and the amount of memory used may vary by machine.

- The **sizeof** operator can be used to return the size of a type in bytes
    - The **sizeof** operator returns the type of `std::size_t`

- **Unsigned integers** only hold positive numbers (and 0), and should generally be avoided unless you're doing bit manipulation

- **Fixed-width integers** are integers with guaranteed sizes, but they may not exists on all architectures. The fast and least integers are the fastest and smallest integers that are at leasy some size. `std::int8_t` and `std::uint8_t` should generally be avoided, as they tend to behave like chars instead of integers.

- **Scientific notation** is a shorthand way of writing lengthy numbers. C++ support scientific notation in conjunction with floating point numbers. The digits in the significand (the part before the e) are called the **significant digits**.

- **Floating point** is a set of types designed to hold real numbers (including those with a fractional component). The **precision** of a number defines how many significant digits it can represent without information loss. A **rounding error** can occur when too many significant digits are stored in a floating point number that can't hold that much precision. Rounding errors happen all the time, even with simple numbers such as 0.1. Because of this, you shouldn't compare floating point numbers directly.

- The **Boolean** type is used to store a `true` or `false` value, generally represented as 1 and 0. You can output the values as `true` and `false` using the `std::boolalpha` operator, and shut it off with `std::noboolalpha`

- **If statements** allow us to execute one or more lines of code if some condition is true. The condition expression of an if-statement is interpreted as a boolean value. An **else statement** can be used to execute a statement when a prior if-statement condition evaluates to false.

- **Char** is used to store values that are interpreted as an ASCII character. When using chars, be careful not tot mix up ASCII code values and numbers. Printing a char as an integer value required use of `static_cast`.

- Angled brackets are typically used in C++ to represent something that needs a parameterizable type. This is used with `static_cast` to determine what data type the argument should be converted to (e.g. `static_cast<int>(x)` will return the value of `x` as an `int`
