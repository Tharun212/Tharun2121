#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int left[], int right[], int left_size, int right_size)
 {
    int i=0,j=0,k=0;
    while (i<left_size&&j<right_size) 
	{
        if (left[i]<right[j])
		 {
            arr[k++]=left[i++];
         }
		  else 
		{
            arr[k++]=right[j++];
        }
    }
    while (i<left_size)
	 {
        arr[k++]=left[i++];
     }
    while (j<right_size)
	 {
        arr[k++]=right[j++];
     }
}
void merge_sort(int arr[], int size) 
{
    if (size<=1) 
	{
        return;
    }
    int mid=size/2;
    int left[mid];
    int right[size-mid];
    for (int i=0;i<mid;i++)
	 {
        left[i]=arr[i];
     }
    for (int i=mid;i<size;i++) 
	{
        right[i-mid]=arr[i];
    }
    merge_sort(left,mid);
    merge_sort(right,size-mid);
    merge(arr,left,right,mid,size-mid);
}
int binary_search(int arr[], int size, int target) 
{
    int left=0;
    int right=size-1;
    while (left<=right)
	 {
        int mid=left+(right-left)/2;
        if (arr[mid]==target)
		{
            return 1;
        } else if (arr[mid]<target) 
		{
            left=mid+1;
        } 
		else 
		{
            right=mid-1;
        }
    }
    return 0;
}
int sum(int arr[], int size, int X) 
{
    merge_sort(arr,size); 
    for (int i=0;i<size;i++)
	 {
        int sum=X-arr[i];
        if (binary_search(arr, size,sum)) 
		{
            return 1; 
        }
    }
    return 0;
}
int main() {
    int arr[10],size,i,X;
    printf("enter the size of the array:");
    scanf("%d",&size);
    printf("enter the element in the array:\t");
    for(i=0;i<size;i++)
    {
    	scanf("%d",&arr[i]);
	}
    printf("enter the value of X:");
    scanf("%d",&X);
    if (sum(arr, size, X)) 
	{
        printf("There exist two integers whose sum is %d\n", X);
    } else {
        printf("No such pair exists.\n");
    }

    return 0;
}
