#include<stdio.h>
#include<string.h>
#define max 100
int top=-1, a[max];
void push(char x)
{
 a[++top]=x;
}
char pop()
{ if(top==-1)
return -1;
else
return a[top--];
}
int prcd(char c)
{ if(c==')')
 return 0;
 else if(c=='+'||c=='-')
 return 1;
 else if(c=='*'||c=='/')
 return 2;
}
void infixtoprefix(char infix[max],char prefix[max])
{
 char temp,x;
 int i=0,j=0;
 strrev(infix);
 while(infix[i]!='\0')
 {
 temp=infix[i];
 if(isalnum(temp))
 {
 prefix[j++]=temp;
 }
 else if(temp==')')
 push(temp);
 else if(temp=='(')
 {
 while((x=pop())!=')')
 {
 prefix[j++]=x;
 }
 }
 else
 { while(prcd(a[top])>=prcd(temp))
 {prefix[j++]=pop();}
 push(temp);
 }
 i++;
 }
 while(top!= -1)
 prefix[j++]=pop();
 prefix[j]='\0';
 strrev(prefix);
}
int main()
{
 char infix[max],prefix[max];
 printf("Enter the infix expression\n");
 gets(infix);
 printf("The infix expression is %s\n",infix);
 infixtoprefix(infix, prefix);
 printf("The prefix expression is %s\n",prefix);
return 0;
}