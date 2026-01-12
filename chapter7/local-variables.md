# 7.3 - Local variables
Local variables are variables that are defined inside a function (including function parameters)

## Local variables have block scope
Local variables habe **block scope**, which means they are in scope from their point of definition to the end of the block they are defined within.

- Function parameters are considered part of the function body scope
- All variables within a scope must be unique

## Local variables have automatic storage duration
A variables **storage duration** (usually just called **duration**) determines what rules govern when and how a variable will be created (instantiated) and destroyed. In most cases, a variables storage duration directly determines its `lifetime`

- For example, local variables have **automatic storage duration**, which means they are created at the point of definition and destoyed at the end of the block they are defined in.
```
int main(){
    int i { 5 }; // i created and initialized here
    double d { 4.0 }; // d created and intialized here

    return 0;

} // d and i are destroyed here
```

## Local variables in nested blocks
Local variables can be nested inside blocks. This works identically to local variables in function body blocks.
- Note that nested blocks are considered part of the scope of the outer block in which they are defined in. Consequently, variables defined in the outer block can be seen inside a nested block.

## Local variables have no linkage
Identifiers have another property named **linkage**. And identifiers **linkage** determines whether a declaration of that same identifier in a different scope refers to the same object (or function)
- Local variables have no linkage. Each declaration of an identifier with no linkage refers to a unique object or function.
```
int main(){
    int x { 2 }; // local variable, no linkage
    {
        int x { 3 }; // this declaration of x refers to a different object then the previous x
    }
    return 0;
}
```

- **Scope** determines where declaration of a single identifier can be seen and used
- **Linkage** determines whether multiple declarations of the same identifier refer to the same object or not.

## Variables should be defined in the most limited scope
If a variable is only used within a nested block, it should be defined inside that nested block.
- This reduces the complexity of your program, and makes the program easier to read

**BEST PRACTICE**
Define variables in the most limited existing scope. Avoid creating new blocks whose purpose is to limit the scope of variables
