# 4.4 - Signed Integers

- An integer is a intergral type that can represent positive and negative whole numbers. The name "signed" meaning it can include a '+ / -' sign

TYPE    MIN SIZE    NOTES
short int   16
int         16      Typically 32 bits on modern arch
long int    32  
long long int 64

- Signed integers are implied when defining integer varaibles
- Signed integer ranges are -(2^n-1) to (2^n-1)-1

## Overflow
- 8-bit signed integer has a range of -128 to 127
- Assigning value 140 to a 8-bit signed integer results in UB
- 'Integer overflow' or 'Arithmetic overflow' results in lost information
