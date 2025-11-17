//Delete a Node at a Given Index in a Circular Linked List using C
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedlistTraverse(struct Node *head)
{
    struct Node *ptr = head;
    int i=0;
    do
    {
        printf("element:%d ->%d\n", i,ptr->data);
        ptr = ptr->next;
        i=i+1;
    } while (ptr != head);
}
//delete first element of the linked list
/*struct Node* deleteAtFirst(struct Node* head){
    struct Node* p=head;
    struct Node* q=head->next;
    while(q->next != head){
        q=q->next;
    }
    q->next=head->next;
    head=head->next;
    free(p);
    return head;
    
}*/
//delete last element of the linked list
/*struct Node* deleteAtLast(struct Node* head){
    struct Node* p=head;
    struct Node* q=head->next;
    while(q->next != head){
        q=q->next;
        p=p->next;
    }
    p->next=head;
    free(q);
    return head;
    
}*/
//delete inbetween index element of the linked list
struct Node* deleteAtIndex(struct Node* head,int index){
    struct Node* p=head;
    struct Node* q=head->next;
    for(int i=0;i<index-1;i++){
        q=q->next;
        p=p->next;
    }
    p->next = q->next;
    free(q);
    return head;
    
}
int main()
{
    // initilize nodes
    struct Node *head;
    struct Node *two;
    struct Node *three;
    struct Node *four;
    // allocate memorey
    head=(struct Node*)malloc(sizeof(struct Node));
    two=(struct Node*)malloc(sizeof(struct Node));
    three=(struct Node*)malloc(sizeof(struct Node));
    four=(struct Node*)malloc(sizeof(struct Node));
    // assign value
    head->data=45;
    two->data=23;
    three->data=67;
    four->data=98;
    // connect nodes
    head->next=two;
    two->next=three;
    three->next=four;
    four->next=head;
    printf("before deleting elements linkedlist is:\n");
    linkedlistTraverse(head);
    printf("After deleting Last element linkedlist is:\n");
    head=deleteAtIndex(head,2);
    linkedlistTraverse(head);
    return 0;
}
