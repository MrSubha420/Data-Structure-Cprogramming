# README — Loops in C

## 1. What is a Loop (minimum 5 points)
- A loop is a control structure that repeats a block of code multiple times.
- Loops reduce code duplication by iterating until a condition changes.
- They are driven by a condition (entry or exit test) or a fixed count.
- Common uses: traversing arrays, repeating calculations, and waiting for events.
- Loops can be controlled with `break` (exit) and `continue` (skip to next iteration).

## 2. Types of Loop
- for loop
- while loop
- do-while loop
- Nested loops (one loop inside another)

## 3. for loop
- Definition: Repeats a block a known or computable number of times; checks condition before each iteration.
- Syntax:
```c
for (initialization; condition; step) {
   /* statements */
}
```
- Example- 
```c
#include <stdio.h>

int main() {
    int i;
    for(i = 0; i < 5; i++) {
        printf("%d\n", i);
    }
    return 0;
}
```
- Common keywords: `for`, `break`, `continue`
- Typical use: indexed iteration with increment value (e.g., for (int i = 0; i < n; i++))
- Typical use: indexed iteration with decrement value (e.g., for (int i = n; i > 0; i--))

## 4. while loop
- Definition: Repeats a block while a condition is true; checks condition before each iteration (entry-controlled).
- Syntax:
```c
while (condition) {
   /* statements */
}
```
- Example- 
```c
#include <stdio.h>

int main() {
    int i = 0;            // initialization

    while(i < 5) {        // condition
        printf("%d\n", i);
        i = i + 2;        // increment
    }

    return 0;
}

```
- Common keywords: `while`, `break`, `continue`
- Typical use: repeat until a condition becomes false (unknown number of iterations)

## 5. do-while loop
- Definition: Repeats a block at least once and then while a condition is true (exit-controlled).
- Syntax:
```c
do {
   /* statements */
} while (condition);
```
- Example- 
```c
#include <stdio.h>

int main() {
    int i = 0;              // initialization

    do {
        printf("%d\n", i);  // loop body
        i = i + 2;          // increment
    } while(i < 5);         // condition

    return 0;
}


```
- Common keywords: `do`, `while`, `break`, `continue`
- Typical use: menu loops or when the body must execute at least once


## 6. Comparison table: for vs while vs do-while

| Feature | for loop | while loop | do-while loop |
|---|---:|---:|---:|
| Condition check | Entry-controlled (checked before each iteration) | Entry-controlled (checked before each iteration) | Exit-controlled (checked after the body) |
| Guaranteed execution | No (may run 0 times) | No (may run 0 times) | Yes (runs at least once) |
| Typical use | Known/finite iteration count, indexed loops | Unknown count, repeat until condition | Menus, input validation — body must run once |



