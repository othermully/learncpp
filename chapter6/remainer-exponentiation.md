# 6.3 - Remainder and Exponentiation

## The remainder operator (`operator%`)

The **remainder operator** (also called the **modulo operator**) is an operator that returns the remainder after doing integer division
- Useful for testing whether a number is evenly divisible by another number
- Also works with negative operands

```
bool isOdd(int x){
    return (x % 2) == 1; // fails when x is -5
    // -5 % 2 is -1, and -1 != 1
}

bool isOdd(int x){
    return (x % 2) != 0; // could also write return (x % 2)
}
```

Best practice: Prefer to compare the results of the remainder operator against 0 is possible

## Exponents
To do exponents in C++, #include the <cmath> header and use the pow() function:
```
#include <cmath>
double x { std::pow(3.0, 4.0) }; // 3 to the 4th power
```

- Note that the param (and return value) of function pow() are of type double. Due to rounding errors in floating-point numbers, the results of pow() may not be precise (even if you pass it integers or whole numbers)

- If you want to do integer exponentiation, you're best off using your own function to do so. The following function implements integer exponentiation (using the non-intuitive "exponentiation by squaring" algorithm for efficiency)

This also checks for overflow

```
#include <cassert> // for assert
#include <cstdint> // for std::int64_t
#include <iostream>
#include <limits> // for std::numeric_limits

// A safer (but slower) version of powint() that checks for overflow
// note: exp must be non-negative
// Returns std::numeric_limits<std::int64_t>::max() if overflow occurs
constexpr std::int64_t powint_safe(std::int64_t base, int exp)
{
    assert(exp >= 0 && "powint_safe: exp parameter has negative value");

    // Handle 0 case
    if (base == 0)
        return (exp == 0) ? 1 : 0;

    std::int64_t result { 1 };

    // To make the range checks easier, we'll ensure base is positive
    // We'll flip the result at the end if needed
    bool negativeResult{ false };

    if (base < 0)
    {
        base = -base;
        negativeResult = (exp & 1);
    }

    while (exp > 0)
    {
        if (exp & 1) // if exp is odd
        {
            // Check if result will overflow when multiplied by base
            if (result > std::numeric_limits<std::int64_t>::max() / base)
            {
                std::cerr << "powint_safe(): result overflowed\n";
                return std::numeric_limits<std::int64_t>::max();
            }

            result *= base;
        }

        exp /= 2;

        // If we're done, get out here
        if (exp <= 0)
            break;

        // The following only needs to execute if we're going to iterate again

        // Check if base will overflow when multiplied by base
        if (base > std::numeric_limits<std::int64_t>::max() / base)
        {
            std::cerr << "powint_safe(): base overflowed\n";
            return std::numeric_limits<std::int64_t>::max();
        }

        base *= base;
    }

    if (negativeResult)
        return -result;

    return result;
}

int main()
{
	std::cout << powint_safe(7, 12) << '\n'; // 7 to the 12th power
	std::cout << powint_safe(70, 12) << '\n'; // 70 to the 12th power (will return the max 64-bit int value)

	return 0;
}
```
