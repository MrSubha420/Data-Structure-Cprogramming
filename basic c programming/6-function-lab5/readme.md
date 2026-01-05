## 1. Defination of Function in c - 
- Defination: In c, we can devide a large program int a basic building blocks wnown as function.
- Which contains set of programming statements enclosed by { }. A function can be call multiple times to reusablity and modularity. 

## 2. Function have three part- 

- Function Declearation : A function must have declared globally in a c program to tell the compiler about the function name , function parameater and return type.
- - Syntax Of Function Declearation :
    ```c
    return_type function_name(argument_list);
    -----------  ------------  -------------
       int         sum        (int a , int b);
    ```

- Function Defination : It contains the actual statements which are to be executed.
- - Syntax Of function Defination :
    ```c
    return_type function_name(argument_list){
      // statements
    }       
  ```
- Function call : Function can be called from any where into the program. The parameater list must not differ in the function call and function decleration.
- - Syntax Of Function call : 
    ```c
    function_name(argument_list);
      -----------   -----------
          sum        (2,3);
   ```
## 3. Types of Function ?
- Function have two types :
- - **User Defined Function:** This type of Function created by the programmer. So he or she can used same "Block of code" declare only one time and used it multiple times.
Example:
```c
#include<stdio.h>
int main(){
int a,b;   
int add(int,int);// Function prototyping
printf("Enter the value of a , b :");
scanf("%d%d",&a,&b);
int sum=add(a,b);// Function call
printf("\n Addition of %d and %d = %d",a,b,sum);
return 0;
}

//Function Defination
int add(int x , int y){
   int sum=0;
   sum=sum+x+y;
   return sum;
}

```
- - **Libary Function:** This type of function already predefined by c language developer which are help to the programmer . And before you used we are need to include the header file such as scanf(),printf() which are avilable in <stdio.h> file.

## 4. Function Prototyping in c :
- Defination: 
- - It is also called signature of a function.
- - It is done to give 

### program1. Write a program implement a simple calculator using the given function 
  - - plus(): add two number 
  - - minus(): substract two number
  - - devide(): devide the number 
  - - multiply() : multiplication of two number
  - - modulo()  : find reminder
  - - power() : find a^b = ?

- [Solution1:]() 

### program2: write a c program create function name as find_fact() used to find factorial given number.
- [Solution2:]() 

### program3: write a c program create a function check the given number strong number or not.
- [Solution3:]()