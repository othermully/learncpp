# 4.11 - Chars

- The char data type was designed to hold a single character. A character can be a single letter, number, symbol, or whitespace.

- The char data type is an integral type, meaning the underlying value is stored as an integer. The integer stored by a char variable are intepreted as an ASCII character

- ASCII Defines a particular way to represent english characters, as numbers between 0 and 127 (called an ASCII code) e.g. 97 is 'a'

- Character literals are always placed between single quotes (e.g. 'g', '1','')

## Intializing chars 
char ch2 { 'a' }; - Intialize with code point for 'a' (stored as integer 97)
char ch1 { 97 }; Not prefered 

char ch{5}; - Initialize with integer 5 (stored as integer 5)
char ch{ '5' }; - ASCII for '5' (stored as integer 53)

- You can print literal chars: std::cout << 'c';
- You can also take chars as input (single chars, not strings)

```
std::cout >> "Enter a character: ";
char ch{};
std::cin >> ch;
```

If you enter more than 1 char here, it will get put into the input queue, so next time you ask for input, it will grab the queued input

- You can use the std::cin.get() function to perform the extraction instead, as this function does not ignore leading whitespace

```
int main(){
    std::cout << "Input a keyboard character: "; // Assume the user enters 'a b' (without quotes)

    char ch{};
    std::cin.get(ch); // Extracts a, leaves " b\n" in stream
    std::cout << "You entered " << ch << '\n";

    std::cin.get(ch); // Extracts space, leaves "b\n" in stream

    return 0;
}
```

```
Input a keyboard character: a b
You entered: a
You entered:
```

## Char size, range and default sign
- Char is defined by C++ to always be 1 byte in size.
- May be signed or unsigned (usually signed)

## Escape sequences
- Starts with '\'
- '\n' - Prints new line
- '\t' - Embeds a horizontal tab

## Quote best practice
- Single character should usually be single-quoted, not double-quoted
- Avoid multicharacter literals (e.g. '56')





