# 5.x - Chapter 5 summary

A **constant** is a value that may not be changed during the program's execution. C++ supports two types of constants: named constants, and literals

A **named constant** is a constant value that is associated with an identifier.A **Literal constant** is a constant value not associated with an identifier.

A variable whose value can not be changed is called a **constant variable**. The **const** keyword can be used to make a variable constant. Constant variablesmust be initialized. Avoid using `const` when passing by value or returning by value.

A **type qualifier** is a keyword that is applied to a type that modifies how tthat type behaves. As of C++23, C+n only supports `const` and `volatile` as type qualifier.

A **constant expression** is an expression that can be evaluated at compile-time. An expression that is not a constant expression is sometimes called a **runtime expression**

A **compile-time constant** is a constant whose value is known at compile-time. A **runtime constant** is a constant whose initialization value isn't known until runtime.

A **constexpr** variable must be a compile-time constant, and initialized with a constant expression. Function parameters cannot be constexpr

**Literals** are values inserted directly into the code. Literals have types, and literal suffixes can be used to change the type of a literal from the default type.

A **magic number** is a literal (usually a number) that either has an unclear meaning or may need to be changed later. Don't use magic numbers in your code. Instead use, symbolic constants

In everyday life, we count using **decimal** numbers, which have 10 digits. Computers use **binary**, which only has 2 digits. C++ also supports **octal (base 8**) and **hexadecimal** (base 16). These are all examples of **numeral systems**, which are collections of symbols (digits) used to represent numbers.

A **string** is a collection of sequential characters that is used to represent text (such as names, words, and sentences). String literals are always placed between double quotes. String literals in C++ are C-style strings, which have strange types and are hard to work with. 

**std::string** offers an easy and safe way to deal with text strings, std::string lives in the <string> header. `std::string` is expensive to intialize (or assign to) and copy.

**std::string_view** provides a read-only access to an existing string (a C-style string literal, a std::string, or a char array) without making a copy. A `std::string_view` that is viewing a string that has been destroyed is sometimes called a **dangling** view. When `std::string` is modified, all views into that `std::string` are **invalidated**, meaning those views are now invalid. Using an invalidated view (other than to revalidate it) will produce UB

Because C-style string literals exist for the entire program, it is okay to set a `std::string_view` to a C-style string literal, and even return such `std::string_view` from a function.

A **substring** is a contiguous sequence of characters withing an existing string.
