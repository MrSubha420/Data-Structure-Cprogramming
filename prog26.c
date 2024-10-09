#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//printing array
void printData(int A[],int size)
{
    for(int i=0;i<size;i++){
    printf("%d \t",A[i]);
    }
    printf("\n");
    printf("\n");
}
int maximum(int A[],int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(max<A[i])
        {
            max=A[i];
        }
    }
    return max;
}
void countsort(int A[],int n)
{
    int i,j;
    //find maximum element in this array
    int max=maximum(A,n);
    //create an dynamic array count with max+1 numbers of element
    int* count=(int *)malloc((max+1)*sizeof(int));
    // initialize 0 all element of counting array
    for(i=0;i<max+1;i++)
    {
        count[i]=0;
    }
    //increment the corrosponding index from count array
    for(i=0;i<n;i++)
    {
        count[A[i]]=count[A[i]]+1;
    }
    i=0;// counter for count array
    j=0;//counter  for given array
    while(i<=max)
    {
        if(count[i]>0)
        {
            A[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++;
        }
    }

}
int main()
{
    int arr[]={2,9,7,4,1,8,4};
    int size=sizeof(arr)/sizeof(int);
    printf("Before sorting array are:\n");
    printData(arr,size);
    countsort(arr,size);
    printf("\n After sorting array is:\n");
    printData(arr,size);
    return 0;
}