//Implement a  dqueue perform all operation using array
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
void enqueuer(struct dqueue *q,int item)
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
//insert element form front end
void enqueuef(struct dqueue *q,int item)
{
    if(isfull(q))
    {
        printf("\n queue is already full");
    }
    else{
            if(q->f == -1)
            q->f=0;
            q->f--;
            q->arr[q->f]=item;
      
      }
}
// delete element from rear end for queue
int dequeuer(struct dqueue *q)
{
    int a=-1;
    if(isempty(q))
    {
        printf("\n queue is already empty");
    }
    else{
            q->r--;
            a=q->arr[q->r];
            if(q->f > q->r)
            q->f=q->r=-1;
        }
   return a;     
}
// delete element for front end from queue
int dequeuef(struct dqueue *q)
{
    int a=-1;
    if(isempty(q))
    {
        printf("\n queue is already empty");
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
            printf("%d->%d \t",i,q.arr[i]);
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
    enqueuer(&q,34);
    enqueuer(&q,26);
    enqueuer(&q,20);
    enqueuer(&q,32);
    display(q);
    dequeuef(&q);
    display(q);
    enqueuef(&q,21);
    display(q);
    return 0;

}
