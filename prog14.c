//write a program in c reverse the given array
#include<stdio.h>
int main()
{
    //initialize the array
    int arr[]={1,2,3,4,5,6,7,8};
    //calculate length of the array
    int length=sizeof(arr)/sizeof(arr[0]);
    printf("\n öriginal array is :\n");
    for(int i=0;i<length;i++)
    {
        printf("%d  \t",arr[i]);
    }
    int temp;
    int j=length;
    // reverse operation ca perfromed
    for(int i=0;i<j;i++)
    {
        temp=arr[i];
        arr[i]=arr[j-1];
        arr[j-1]=temp;
        j--;
    }
    // printing elements of an arry after reversed 
    printf("\n after reersed array is:\n");
    for(int i=0;i<length;i++)
    {
        printf("%d \t",arr[i]);
    }
    return 0;
}