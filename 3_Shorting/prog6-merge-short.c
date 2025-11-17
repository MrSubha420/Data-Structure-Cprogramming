//implement mergesort algorithm in c
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
    printf("\n");
}
// conquer method 
void merge(int A[],int low,int mid,int high)
{
  int i;//index of subArray1
  int j;//index of subarray2
  int k;// index of new array where sorted array stored
  // ctreate a new array
  int arr[100];
  i=low;
  j=mid+1;
  k=low;
  while(i<=mid && j<=high) 
  {
    if(A[i]<A[j])
     {
        arr[k]=A[i];
        i++;
        k++;
    }
    else
    {
        arr[k]=A[j];
        j++;
        k++;
    }

  } 
  while(i<=mid){
    arr[k]=A[i];
    k++;
    i++;
  }
   while(j<=high){
    arr[k]=A[j];
    k++;
    j++;
  }
  //copy all the elements of newly created array arr[] to actual array A[]
  for(int i=low;i<=high;i++)
  {
    A[i]=arr[i];
  }
}
// deide method
void mergesort(int A[],int low,int high)
{
    int mid;
    if(low<high){
    mid=(low+high)/2;
    mergesort(A,low,mid);
    mergesort(A,mid+1,high);
    merge(A,low,mid,high);
    }
}
int main()
{
    int A[]={6,4,2,1,9,8,3,5};
    int size=sizeof(A)/sizeof(int);
    int low=0;
    int high=size-1;
    //Before sorting the array is
    printf("Before sorting the array is: \n");
    printData(A,size);
    mergesort(A,low,high);
    //After sorting the array is
    printf("After sorting the array is :\n");
    printData(A,size);
    return 0;
}