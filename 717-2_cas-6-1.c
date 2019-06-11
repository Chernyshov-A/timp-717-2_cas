#include "stdio.h"
#define true 1
#define false 0

int sorting_function(int *arr,int arr_len)
{ int temp = 0;
  int d = arr_len; 
  int flag = false;
  int count = 0;

    while(flag || (d>1))
    {
        if( d > 1){d = d/1.24733;}
        else { d = 1; }
        flag = false;
        for(int i = 0; d + i < arr_len; i++)
        {
            if(arr[i] > arr[d+i])
            {
                temp = arr[i];
                arr[i] = arr[d+i];
                arr[d+i] = temp;
                count++;
                flag = true;
            }
        }     
            
    }
    return count;
}

int printing_function(int *arr,int arr_len)
{
    for(int i = 0; i < arr_len; i++)
    {
        if(i!=(arr_len-1))
        {
            printf("%d ",arr[i]);
        }else
        {
            printf("%d",arr[i]);
        }
    }
    printf("\n");
}
int main()
{
    int n; scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    sorting_function(arr,n);
    printing_function(arr,n);
}