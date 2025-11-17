//Insertion Sort Implementation in C (with pass-by-pass output).
#include<stdio.h>
#include<stdlib.h>
//printing array
void printData(int A[],int size)
{
    for(int i=0;i<size;i++){
    printf("%d \t",A[i]);
    }
    printf("\n");
    printf("\n");
}
void insertionsort(int arr[],int size)
{
    int key,j;
    //this loop for pass
    for(int i=1;i<size;i++)
    {
        key=arr[i];
        j=i-1;
        //this loop for each pass
        while(j>=0 && arr[j]>=key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        printf("After complrate pass %d array is: \n",i);
        printData(arr,size);
    }
}
int main()
{
    int A[]={40,20,60,10,50,30};
    int size=sizeof(A)/sizeof(int);
    //Before sorting the array is
    printf("Before sorting the array is: \n");
    printData(A,size);
    insertionsort(A,size);
    //After sorting the array is
    printf("After sorting the array is :\n");
    printData(A,size);
    return 0;
}
