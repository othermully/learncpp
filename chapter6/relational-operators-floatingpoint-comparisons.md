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
