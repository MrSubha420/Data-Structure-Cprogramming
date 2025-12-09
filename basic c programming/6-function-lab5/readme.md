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
- - **User Defined Function:** 