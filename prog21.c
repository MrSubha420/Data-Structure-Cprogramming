// Additie boublesort Algorithm
#include<stdio.h>
#include<stdlib.h>
void printArray(int* arr,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d \t",arr[i]);
    }
    printf("\n");
}
void bubleSort(int* arr,int size)
{
    int temp;
    int isSort=0;
    for(int i=0;i<size-1;i++)
    {
    printf(" working pass is :%d \n",i);
     isSort=1;
     for(int j=0;j<size-1-i;j++)
         {
              // swaping lower element and higher element
              if(arr[j]>arr[j+1])
              {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                isSort=0;
              }
         }
         if(isSort){ return ;}
    }
}
void main()
{
    int arr[]={2,4,1,3,7,8,5};
    int size=sizeof(arr)/sizeof(int);
    printf(" Before sorting array element is:\n");
    printArray(arr,size);
    bubleSort(arr,size);
    printf(" After sorting array element is:\n");
    printArray(arr,size);
}