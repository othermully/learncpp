# 7.1 - Compound Statements (blocks)

A **compound statement** (also called a **block** or **block statement**) is a group of zero or more statements that is treated by the compiler as if it were a single statement.

Block begin with a `{`, and end with a `}` symbol, with the statements to be executed being placed in between. Blocks can be used anywhere a single statement is allowed. No semicolon is needed at the end of a block.

- The body of a function is considered a block
- Functions can't be nested inside other functions, but blocks can be nested inside other blocks.

## Use blocks to execute multiple statements conditionally
- By default, and `if statement` executes a single statement if the condition evaluates to `true`. 
- If you want to execute multiple statements within an `if statement`, use a block statment

```
if (value >= 0){
    std::cout << "Statement 1";
    std::cout << "Statement 2";
}
```

## Keep nesting level of functions 3 or less.
