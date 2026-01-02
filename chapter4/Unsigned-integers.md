# 4.5 - Unsigned integers
- Unsigned integers are integers that can only hold non-negative whole numbers

## Defining unsigned integers
``` 
unsigned short us;
unsigned int ui;
unsigned long ul;
unsigned long long ull;
```

## Unsigned integer range
- A 1-byte usigned integer has a range of 0-255
- 0 to (2^n)-1
- When no negative numbers are required, unsigned integers are well suited for networking and systems with little memory, because unsigned integers can store more positive numbers without taking up extra memory


## Unsigned integer overflow
- If a unsigned value is out of range, it is divided by one greater than the largrest number of the type, and only the remainder is kept

- The number 280 is too big to fit in our 1-byte range of 0 to 255
    - 280 gets divided by 256, getting 1 remainder 24. 24 is what is stored.
- This is called 'modulo wraping'

## When to use unsigned numbers:
- Preferred when dealing with bit manipulation
- Useful in some algorithms like encryption and random number gen
- Array indexing
- Processor/memory limited context, performance reasons

