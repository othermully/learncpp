# 7.4 - Intro to global variables
Variables declared outside of a function are called **global variables**

## Declaring global variables
By convension, global variables are declared at the top of the file, below the includes, in the global namespace

## The scope of global variables
Identifiers declared in the global namespace have **global namespace scope** (commonly called **global scope**
- Their duration is until the end of the file in which they are declared

Global variables can also be defined inside a user-defined namespace:
```
namespace Foo{ // Foo is defined in the global scope
    int g_x{}; // g_x is now inside the Foo namespace, but still global var
}
```

- You can access `g_x` via `Foo:g_x` anywheres in the file

**Best practice**
- Prefer defining global variables inside a namespace rather than in the global namespace.

## Global variables have static duration
Global variables are created when the program starts (before `main()` begins execution), and destroyed when it ends. This is called **static duration**
- Variables with static duration are sometimes called **static variables**

## Naming conventions
- Prefix global variables with "g" or "g_" to indicate they are global.
- Global variables defined in user-defined namespace can omit the prefix

## Global variable initialization
Variables with static duration are zero-initialized by default
- Non-constant global variables can be optionally initialized
```
int g_x; // No explicit initializer (zero-initialized by default)
int g_y{}; // Value intialized (resulting in zero-init)
int g_z{ 1 }; // list initialized with specific value
```

### Constant global variables
Just like local variables, global variables can be constant. As with all constants, constant global variables must be initialized.
```
const int g_x; // error: constant variables must be initialized
constexpr int g_w; // error: constexpr variables must be initialized

cont int g_y { 1 }; // const global variable g_y, initialized with value
constexpr int g_z { 2 }; // constexpr global variable g_z with value
```
