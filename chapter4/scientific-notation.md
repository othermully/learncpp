# 4.7 - Scientific Notation

- Useful shorthand for writing length numbers in a concise manner
- significand x 10^exponent
- 1.2 x 10^4, 1.2 is the significand and 4 is the exponent
    - Since 10^4 evaluates to 10,000, 1.2 x 10^4 = 12,000

- Consider 5972200000000000000000000 kg. Too large to even fit inside of a 8-byte integer. In scientific notation, this would be written as 5.9722 x 10^24 kg.
- This makes it easier to compare the magnitude of two extremely large or small numbers, simply by comparing the exponent

- Because it can be hard to type or display exponents in C++, we use the letter 'E or e' to represent the "time 10 to the power of" part of the equation

- 1.2 x 10^4 would be written as 1.2e4
- 5.9722 x 10^24 would be written as 5.9722e24

- For numbers smaller than 1, the exponent can be negative
    - 5 * 10^-2 = 5e-2

## Significant Digits
- The part before the 'e' are called significant digits, the more there are, the more precise a number is

- We'd write 3.14 as 3.14e0 since there are 3 numbers in the significand
- 3.14159 would be 3.14159e0

## How to convert decimal to scientific notation
- Your exponent starts as zero
- If the number has no explicit decimal point (e.g. 123), it is implicitly on the right end (e.g. 123.)
- Slide the decimal point left or right so there is only one non-zero digit to the left of the decimal
    - Each place you slide the decimal point to the left, increase the exponent by 1
    - Each place you slide the decimal point to the right, decrease the exponent by 1
- Trim off any leading zeros (On the left end of the significand)
- Trim off any trainling zeros (On the right end of the significand) only if the original number had no decimal point. We're assuming they're not significant, if any additional information suggest they are significant, you can keep them.

## Examples:
Start with: 600.410
Slide decimal point left 2 spaces: 6.00410e2
No leading zeros to trim: 6.00410e2
Don't trim trailing zeros: 6.00410e2 (6 significant digits)

Start with: 0.0078900
Slide decimal point right 3 spaces: 0007.8900e-3
Trim leading zeros: 7.8900e-3
Don't trim trailing zeros: 7.8900e-3 (5 significant digits)

Start with: 42030 (no information to suggest the trailing zero is significant)
Slide decimal point left 4 spaces: 4.2030e4
No leading zeros to trim: 4.2030e4
Trim trailing zeros: 4.203e4 (4 significant digits)

Start with: 42030 (assuming the trailing zero is significant)
Slide decimal point left 4 spaces: 4.2030e4
No leading zeros to trim: 4.2030e4
Keep trailing zeros: 4.2030e4 (5 significant digits)

## Tip
- You may see a number written with an explicit trailing decimal point. This is an indication that the preceeding zeros are significant
    - 2100. = 2.100e3 (Trailing zeros known significant)

- From a technical standpoint, the numbers 87.0 and 87.000 have the same value (and the same type). When C++ stores either of these numbers in memory, it will store just the value 87. And once stored, there is no way to determine from the stored value wich of the two numbers was originally input
