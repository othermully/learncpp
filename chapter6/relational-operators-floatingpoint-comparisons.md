# 6.7 - Relational operators and floating point comparisons
**Relational operators** are operators that let you compare two values. There are 6 relational operators

**Best practice** 
- Don't add unnecessary == or != to conditions. 

## Comparison of calculated floating point values can be problematic

```
constexpr double d1{ 100.0 - 99.99 }; // should equal 0.01 
constexpr double d2 { 10.0 - 9.99 }; // should equal 0.01

if (d1 == d2)
    d1 == d2
else if (d1 > d2)
    d1 > d2
else if (d1 < d2)
    d1 < d2
```

The above code will result in d1 > d2, because if you inspect the value of d1 and d2 in the debugger, d1 = 0.0100000000005116 and d2 = 0.0099999999987623. Both numbers are close 0.01, but d1 is greater than, and d2 is less than.

Comparing floating point values using any of the relational operators can be dangerous. This is because floating point values are not precise, and small rounding errors in the floating point operands may couse them to be slightly smaller or slightly larger than expected.

- If the consequence of getting a wrong answer when the operands are similar is acceptable, then using these operators can be acceptable. This is an application specific decision.

**WARNING**
- Avoid using operator== and operator!= to compare floating point values if there is any chance those values have been calculated

**TIP**
It is safe to compare a floating point literal with a variable of the same type that has been initialized with a literal of the same type, so long as the number of significant digits in each literal does not exceed the minimum precision for that type.

## Comparing floating point numbers

The most common method of doing floating point equality involves using a function that looks to see if two numbers are equal. The valued used to represent "close enough" is traditionally called an **epsilon**. Epsilon is generally defined as a small positive number (e.g. 0.00000001, sometimes written 1e-8).

New developers often try to write their own "close enough" functions like this:
```
// absEpsilon is an absolute value
bool aproxEqualAbs(double a, double b, double absEpsilon){
    // if the distance between a and b is less than or equal to absEpsilon, then a and b are "close enough"

    return std::abs(a - b) <= absEpsilon;
}
```

`std::abs()` is a function in the <cmath> header that returns the absolute value of its argument. So `std::abs(a - b) <= absEpsilon` checks if the distance between a and b is less than or equal to whatever epsilon value representing "close enough" was passed in. If a and b are close enough, the function returns true to indicate if they're equal. Otherwise, it returns false.

While this function can work, its not great. An epsilon of 0.00001 is good for inputs around 1.0, too big for inputs around 0.0000001, and too small for inputs like 10,000.

Comparison between floating point numbers is a difficult topic, and there's no "one size fits all" algorithm that works for every case. However, the approxEqualAbsRel() functiohn with an absEpsilon of 1e-12 and a relEpsilon of 1e-8 should be good enough to handle most cases you'll encounter.
