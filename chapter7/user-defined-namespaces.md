# 7.2 - User defined namespaces

Namespaces can be defined using the `namespace` keyword. 

- We can tell the compiler to use something within a namespace using the `scope resolution operator` or via `using statement`

- Naming collisions happen when two identical identifiers are introduced in the same scope.

## Accessing a namespace with the scope resolution operator (::)

```
namespace Goo{
    int doSomething(int x, int y){
        return x + y
    }
}

```
- You can access doSomething() via `Goo::doSomething(4, 3)`
- Just using `::doSomething` will make the compiler look in the global namespaceold_oil_painting.png

## Identifier resolution from within a namespace
If an identifier inside a namespace is used and no scope resolution is provided, the compiler will first try to find a matching declaration in that same namespace. If no matching identifier is found, the compiler will then check each containing namespace in sequence to see if a match is found, with the global namespace being checked first.

## Forward declaration of content in namespaces
Header files are used to propagate forward declarations. For identifiers inside a namespace, those forward declarations also need to be inside the same namespace

add.h
```
#ifndef ADD_H
#define ADD_H

namespace BasicMath{
    int add(int x, int y);
}
#endif
```

add.cpp
```
#include "add.h"
namespace BasicMath{
    int add(int x, int y){
        return x + y;

    }
}
```

main.cpp
```
#include "add.h" // for BasicMath::add()
#include <iostream>

int main(){
    std::cout << BasicMath::add(4,3) << '\n';
    return 0;
}
```

- If the forward declaration for `add()` wasn't placed inside namespace `BasicMath`, then `add()` would be declared in the global namespace instead, and the compiler would complain that it hasn't seen a declaration for the call to `BasicMath::add(4,3)`
- If the definition of function `add()` wasnt inside namespace `BasicMath`, the linker would complain that it couldn't find a matching definition for the call to `BasicMath::add(4,3)`

## Mutiple namespace blocks are allowed
Its legal to declare namespace blocks in multiple locations (either across multiple files, or multiple places within the same file). All declarations within the namespace are considered part of the namespace

## Nested namespaces
Namespaces can be nested inside other namespaces
- Access nested namespace like `Foo::Goo::add`

## Namespace aliases
Because typing the qualified name of a variable or function inside a nested namespace can be painful, C++ allows you to create **namespace alises**, which allow us to temporaily shorten a long sequence of namespaces of namespaces into something shorter:
```
namespace Foo::Goo{
    int add(int x, int y){
        return x + y;
    }
}

int main(){
    namespace Active = Foo:Goo; // active now refers to Foo::Goo
    std::cout << Active::add(1,2);

} // The Active alias ends here
```

## How to use namespaces
Its worth noting that namespaces in C++ were not originally designed as a way to implement an information hierarchy -- they were designed primarily as a mechanism for preventing naming collisions. 
- Small applications developed for your own use typically do not need to placed in namespaces. However, for larger personal projects that include lots of third party libraries, namespacing your code can help prevent naming collisions with libraries that aren't properly namespaced.
- Can be used for multi-organization code with multiple teams to prevent naming collisions.
- Autocomplete will automatically show names in namespaces




