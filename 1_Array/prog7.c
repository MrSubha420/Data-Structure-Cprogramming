//find the average of the array elements
#include<stdio.h>
int main()
{
    //initialize the array
    int arr[]={1,2,3,4,5,6,7,8};
    //calculate length of the array
    int length=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    //calculate sum of an array
    printf("\n array elements are: \n");
    for(int i=0;i<length;i++)
    {
        printf("%d \t",arr[i]);
        sum=sum+arr[i];
    }
    //calculate average
    float avg=(float)sum/length;
    printf("\n average of an array is =%f \n ",avg);
    return 0;
}     