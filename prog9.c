// Delete any element from the arry
#include<stdio.h>
void main()
{
    int arr[20]={18,30,15,70,12};
    int k,i,j,pos,n=5;
    printf("Given array elements are:");
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    }
    printf("\n choose any element from this arry which will be delete:");
    scanf("%d",&k);
    // get the index of the elent which will be deleted
    for(i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            pos =i;
            break;
        }
    }
    //shifting left side all the element 
    for (j=pos;j<n;j++)
    {
        arr[j]=arr[j+1];
    }
    n--;
    printf("\n After deleted the element thre array element are: \n");
    for (i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    }
}