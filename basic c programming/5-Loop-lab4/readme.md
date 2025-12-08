# Loops in C

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

// output : 0 1 2 3 4
```
- Common keywords: `for`, `break`, `continue`
- Typical use: indexed iteration with increment value=1 (e.g., for (int i = 0; i < n; i++))
- Typical use: indexed iteration with decrement value=1 (e.g., for (int i = n; i > 0; i--))
- Typical use: indexed iteration with increment value=2 (e.g., for (int i = n; i > 0; i=i+2))
- Typical use: indexed iteration with decrement value (e.g., for (int i = n; i > 0; ){
   //statements
   i=i+2;
})
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

// 0 2 4

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
//output : 0 2 4

```
- Common keywords: `do`, `while`, `break`, `continue`
- Typical use: menu loops or when the body must execute at least once


## 6. Comparison table: for vs while vs do-while

| Feature | for loop | while loop | do-while loop |
|---|---:|---:|---:|
| Condition check | Entry-controlled (checked before each iteration) | Entry-controlled (checked before each iteration) | Exit-controlled (checked after the body) |
| Guaranteed execution | No (may run 0 times) | No (may run 0 times) | Yes (runs at least once) |
| Typical use | Known/finite iteration count, indexed loops | Unknown count, repeat until condition | Menus, input validation — body must run once |

## 7. Infinite loop 
 - Defination : An infinite loop is a loop that never stops running because its termination condition is never met or no condition is provided.

 - Syntax: 
 - - condition does not given: 
      ```c
        for(;;) {
            printf("Hi");
         }
      ```
 - - Variable inside condition never updates : 
       ```c
      int i;
        for(i=0;i<5;) {
            printf("Hi");
         }
      ```
      or 

      ```c
      int i = 0;
        while(i < 5) {
            printf("%d", i);
             // i is NOT updated → loop never stops
          }
      ```
 - - Condition is always true : 
   ```c
      while(1) {
         printf("Hello");
       }
   ```

## 8. Break statement in c.
- Defination: The Break statement is used to exit the loop irrespective of wheather the break is encountered.
- Example: 
 ```c
 #include <stdio.h>
 int main(){
   int i;
  for (i = 1; i<100;i++){
   printf("%d \n",i);
   if(i==5){
      break;
   }
  }
 } 

 // output: 1 2 3 4 5
```
## 9. Continue statement in c. 
- Defination : The continue statament is used to immediately move next itaration or skip everything in the current itaration.
- Example:
```c
#include <stdio.h>

int main() {
    for(int i = 1; i <= 5; i++) {
        
        if(i == 3) {
            continue;   // skip this iteration
        }

        printf("%d\n", i);
    }

    return 0;
}

//output: 1 2 4 5
```
## 10 Double Variable loop- 
- Defination: A double variable loop is a loop where two variables are initialized, updated, and used together inside the same loop header.
- Characteristics : if double condition are there used the latest condition like(cod1. , cond2.) used cond2. because comma operator , evaluates all expressions from left to right.
- Syntax : 
```c
for(i = start1, j = start2; condition; update1, update2)
{
   //statements
}
```
- Example:
```c 
#include <stdio.h>

int main() {
    int i, j;
    for(i = 0, j = 1; i < 2, j < 3; i++, j++) {
        printf("%d \n", i*j);
    }
    return 0;
}
//output: 0 2
```
or
```c
#include <stdio.h>

int main() {
    int i, j;
    for(i = 0, j = 1; i < 4; i++, j++) {
        printf("%d \n", i*j);
    }
    return 0;
}
//output : 0 2 6 12
```

or 
```c
#include <stdio.h>

int main() {
    int i, j;
    for(i = 0, j = 1; i < 2, j < 5; i++, j++) {
        printf("%d \n", i*j);
    }
    return 0;
}
//output : ?
```
## Enquary questions- ( find the output )
- Q1 : 
```c
  int main() {
   int skip=3;
    for(int i = 1; i <= 10; i++) {
        
        if(i != skip) {
            continue;   // skip this iteration
        }
        else{
         printf("%d\n", i);
        }
    }

    return 0;
   }

 //output : ?  
 ```
- Q2 : 
```c
#include <stdio.h>

int main() {
    int i = 0;
    for( ; ; i++) {
        if(i == 4) break;
        printf("%d ", i);
    }
    return 0;
}
// output = ?
```
- Q3 : 






   
   







