// Implement a stack perform all operation using array
// include prog:32, prog:33, prog:34
#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    int *arr;
};
// check the stack is full or not
int isfull(struct stack *q)
{
    if (q->top == q->size - 1)
    {
        printf("\n stack full");
        return 1;
    }
    else
    {
        // printf("\n not stsck full");
        return 0;
    }
}
// check the stack is empty or not
int isempty(struct stack *q)
{
    if (q->top == -1)
    {
        printf("\n stack empty");
        return 1;
    }
    else
    {
        // printf("\n stack not empty");
        return 0;
    }
}
// insert element from the queue
void push(struct stack *q, int item)
{
    if (isfull(q))
    {
        printf("\n stack is already full");
    }
    else
    {
        q->top++;
        q->arr[q->top] = item;
        printf("\n stack index:%d inserted element=%d", q->top, item);
    }
}
// delete element from queue
int pop(struct stack *q)
{
    int a = -1;
    if (isempty(q))
    {
        printf("\n stack is already empty");
    }
    else
    {
        a = q->arr[q->top];
        printf("\n queue index:%d delete element=%d", q->top, a);
        q->top--;
    }
    return a;
}
void display(struct stack *s)
{
    if (isempty(s))
    {
        printf("\n stack is already empty");
    }
    else
    {
        int i;
        for(i=0;i<s->top+1;i++)
        {
            printf("|%d -->\t",i);
            printf("%d \t",s->arr[i]);
        }
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("\n Initiallay....");
    isempty(sp);
    isfull(sp);
    printf("\n Starting inserting elements from the stack....");
    push(sp, 56);
    push(sp, 45);
    push(sp, 90);
    push(sp, 32);
    push(sp, 21);
    push(sp, 12);
    printf("\n                                                                                |");
    printf("\n --------------------------------------------------------------------------------\n");
    display(sp);
    printf("\n --------------------------------------------------------------------------------\n");
    printf("\n                                                                                |");
    printf("\n Starting deleting elements from the stack....");
    pop(sp);
    pop(sp);
    printf("\n --------------------------------------------------------------------------------\n");
    display(sp);
    printf("\n --------------------------------------------------------------------------------\n");
    return 0;
     
}
