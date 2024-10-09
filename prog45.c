// Implement a simple queue perform all operation using array
#include <stdio.h>
#include <stdlib.h>
struct dqueue
{
    int f;
    int r;
    int size;
    int *arr;
};
// check the queue is full or not
int isfull(struct dqueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        printf("\n queue full");
        return 1;
    }
    else
    {   
        // printf("\n not queue full");
        return 0;
    }
}
// check the queue is empty or not
int isempty(struct dqueue *q)
{
    if (q->f == q->r)
    {
         printf("\n queue empty");
        return 1;
    }
    else
    {
        // printf("\n queue not empty");
        return 0;
    }
}
// insert element from the queue
void enqueue(struct dqueue *q, int item)
{
    if (isfull(q))
    {
        printf("\n queue is already full");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = item;
         printf("\n queue index:%d insered element=%d",q->r,item);

    }
}
// delete element from queue
int dequeue(struct dqueue *q)
{
    int a = -1;
    if (isempty(q))
    {
        printf("\n queue is already empty");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
        printf("\n queue index:%d delete element=%d",q->f,a);
    }
    return a;
}

    

int main()
{
    struct dqueue q;
    q.size = 5;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    printf("\n Initiallay....");
    isempty(&q);
    isfull(&q);
    printf("\n Starting inserting elements from the queue....");
    enqueue(&q,7);
    enqueue(&q,9);
    enqueue(&q,43);
    enqueue(&q,78);
    enqueue(&q,56);
    printf("\n Starting deleting elements from the queue....");
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q,78);
     enqueue(&q,7);
      enqueue(&q,70);
       enqueue(&q,79);
       dequeue(&q);
    return 0;
}
