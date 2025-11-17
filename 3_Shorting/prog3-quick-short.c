//implement quick sort 
#include<stdio.h>
#include<stdlib.h>
//printing array
void printData(int A[],int size)
{
    for(int i=0;i<size;i++){
    printf("%d \t",A[i]);
    }
    printf("\n");
}
//partion of array
int partition(int A[],int low ,int high)
{
    int pivot=A[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
        while(A[i]<=pivot)
        {
            i++;//increasing i index
        }
        while(A[j]>pivot)
        {
            j--;//decreasing j index
        }
        if(i<j)
        {
            // swaping element of the array i position and j position 
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<j);
    // After i element and j element cross each other swap j element in arry with pivot
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
}
// quickSort which is sort the array
void quickSort(int A[],int l,int h)
{
    int partitionIndex;//After partition index is store this element
    if(l<h){
    partitionIndex= partition(A,l,h);
    // After partition sort left subArray
    quickSort(A,l,partitionIndex-1);
    //After partition  sort right subArray
    quickSort(A,partitionIndex+1,h);
    }
}
int main()
{
    int A[]={3,6,8,4,6,10,5,15,11};
    int size=sizeof(A)/sizeof(int);
    int low=0;
    int high=size-1;
    //Before sorting the array is
    printf("Before sorting the array is: \n");
    printData(A,size);
    quickSort(A,low,high);
    //After sorting the array is
    printf("After sorting the array is :\n");
    printData(A,size);
    return 0;
}