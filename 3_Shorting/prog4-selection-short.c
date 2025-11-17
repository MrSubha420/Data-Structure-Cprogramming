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
void selectionsort(int arr[],int size)
{
    int min,temp;
    for(int i=0;i<size-1;i++)
    {
        min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        //swap Arr[min],Arr[i]
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;

    }
}
int main()
{
    int A[]={3,6,8,4,6,10,5,15,11};
    int size=sizeof(A)/sizeof(int);
    //Before sorting the array is
    printf("Before sorting the array is: \n");
    printData(A,size);
    selectionsort(A,size);
    //After sorting the array is
    printf("After sorting the array is :\n");
    printData(A,size);
    return 0;
}