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
- Common keywords: `do`, `while`, `break`, `continue`
- Typical use: menu loops or when the body must execute at least once
