//implement radix sort their tree case time complexity and compare this
//best case:pai(n+k)
//worst case: O(kn)
//Average case: theta(nk)
#include<stdio.h>
#include<stdlib.h>
//printing array
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d \t",arr[i]);
    }

}
// maximum function for getting maximum element of this array
int maximum(int arr[],int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    return max;
}
// counting sort used sort the array based on place value
void countingSort(int arr[],int size,int place)
{
    //create a new array
    int output[size+1];
    int max=(arr[0]/place)%10;
    for(int i=1;i<size;i++)
    {
        if(((arr[i]/place)%10)>max)
        {
            max=arr[i];
        }
    }
    int count[max+1];
    for(int i=0;i<max;++i)
    {
        count[i]=0;
    }
    // calculate count of elements
    for(int i=0;i<size;i++)
    {
        count[(arr[i]/place)%10]++;
    }
    //calculate commutative count
    for(int i=1;i<10;i++)
    {
        count[i] += count[i-1];
    }
    //place the element in sorted order
    for(int i=size-1;i>=0;i--)
    {
        output[count[(arr[i]/place)%10]-1]=arr[i];
        count[(arr[i]/place)%10]--;
    }
    // now copy the output array elements into original array
    for(int i=0;i<size;i++)
    {
        arr[i]=output[i];
    }
}
void radixSort(int arr[],int size)
{
    // get maximum element of the array
    int max=maximum(arr,size);
    // Applay counting sort based on place value
    for(int place=1;max/place>0;place *=10)
    {
        countingSort(arr,size,place);
    }

}
int main()
{
    int arr[]={1,20,56,607,409,500,600,987,1040,5678,4567,8976};
    int size=sizeof(arr)/sizeof(int);
    printf("\n before sorting array elements are:\n");
    printArray(arr,size);
    radixSort(arr,size);
    printf("\n After sorting array are :\n ");
    printArray(arr,size);
    return 0;

}
