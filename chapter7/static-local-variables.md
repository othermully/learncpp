# 7.11 - Static local variables

the `static` keyword has different meanings in different contexts

Global variables have static duration, which means they are created when the program starts and destoyed when the program ends

`static` keyword gives a global identifier internal-linkage, which means the identifier can only be used in the file in which it is defined.

## Static local variables

Local variables have automatic duration by default, which means they at created at the point of definition and destroyed when the block is exited

Using the `static` keyword on a local variable changes its duration from automatic to static duration. This means the variables is now created at the start of the program, and destroyed at the end of the program (just like a global variable). As a result, the statis variable will retain its value, even after it goes out of scope!

## Common use case - ID Generation
```
int generateID(){
    static int s_itemID{ 0 };
    return s_itemID++; // makes a copy of s_itemID increments the real s_itemID, then returns the copy
}
```

A static local variable has block scope like a local variable, but its lifetime is until the end of the program like a global variable.

## Static local constants
A static local variable can be made const (or constexpr). One good use for a const static local variable is when you have a function that needs to use a const value, but creating or intializing the object is expensive (e.g. you need to read the value from a database). If you used a normal local variable, the variable would need to be created and initialized every time the function was executed. With a const/constexpr static local variable, you can create and initialize the expensive object once, and then reuse it whenever the function is called.

**Key insight** 
Static local variables are best used to avoud expensive local object initialization each time a function is called

**Best practice**
Const static local variable are generally okay to use.
Non-Const static local variables should generally be avoided. If you do use them, ensure the variable never needs to be reset, and isn't used to alter program flow.
