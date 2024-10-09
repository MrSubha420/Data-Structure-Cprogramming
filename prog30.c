//implement minheap in the complexity O(nlogn)
#include<stdio.h>
#include<stdlib.h>
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d \t",arr[i]);
    }
    printf("\n");
    printf("\n");
}
//swaping two elements of the array
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
//heapify function 
void heapify(int arr[],int n,int i)
{
    int min=i;
    int left=2*i+1;
    int right= 2*i+2;
    //check the root element is less than left child element
    if(left<n && arr[left]<arr[min])
    {
        min=left;
    }
    //check the root element is less than right child element
     if(right<n && arr[right]<arr[min])
    {
        min=right;
    }
    // checking the element of array with laggest position is equalto ith position 
    if(min != i)
    {
        swap(&arr[i],&arr[min]);
        heapify(arr,n,min);
    }
}
// now start heap sort
void heapsort(int arr[],int n)
{
    // buid a min heap
    for(int i=n/2 -1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    // heap sort
    for(int i=n-1;i>=0;i--)
    {
        // swap element and ith position element of the array
        swap(&arr[0] , &arr[i]);
        heapify(arr,i,0);
    }

}
int main()
{
    int arr[]={1,12,9,5,10};
    int size=sizeof(arr)/sizeof(int);
    printf("Befoe sorting array elements are:\n");
    printArray(arr,size);
    heapsort(arr,size);
    printf("After sorting Array elements are:\n");
    printArray(arr,size);
    return 0;
}