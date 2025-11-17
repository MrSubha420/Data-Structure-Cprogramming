//Implement a simple queue perform all operation using array
#include<stdio.h>
#include<stdlib.h>
struct dqueue
{
    int f;
    int r;
    int size;
    int* arr;
};
// check the queue is full or not
int isfull(struct dqueue *q)
{
    if(q->r == q->size-1)
    {
        return 1;
    }
    else {
        return 0;
    }
}
// check the queue is empty or not
int isempty(struct dqueue *q){
    if(q->f==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
// insert element from the queue
void enqueue(struct dqueue *q,int item)
{
    if(isfull(q))
    {
        printf("\n queue is already full");
    }
    else{
            if(q->f == -1)
            q->f=0;
            q->r++;
            q->arr[q->r]=item;
      
      }
}
// delete element from queue
int dequeue(struct dqueue *q)
{
    int a=-1;
    if(isempty(q))
    {
        printf("\n queue is already full");
    }
    else{
            q->f++;
            a=q->arr[q->f];
            if(q->f > q->r)
            q->f=q->r=-1;
        }
   return a;     
}


// printing element from the queue
void display(struct dqueue q)
{
    if(q.r==-1)
    {
        printf("\n queue is empty");
    }
    else{
        int i;
        printf("\n Queue :");
        for(i=q.f;i<=q.r;i++)
        {
            printf("%d \t",q.arr[i]);
        }
    }
}

int main()
{
    struct dqueue q;
    q.size=5;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    printf("Initiallay....");
    display(q);
    printf("\n After adding element...");
    enqueue(&q,12);
     enqueue(&q,1);
      enqueue(&q,15);
       enqueue(&q,19);
       enqueue(&q,7);
    display(q);
     printf("\n After removing element...");
    dequeue(&q);
    dequeue(&q);
     dequeue(&q);
      dequeue(&q);
    display(q);
    enqueue(&q,56);
    return 0;

}
