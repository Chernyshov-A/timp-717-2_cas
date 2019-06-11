#include "stdio.h"

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

 int sorting_function(int *arr,int arr_len)
{ 
    int j;
	int temp = 0;
    int count = 0;
    int  d = arr_len / 2;
	for(; d > 0; d /= 2){
        for(int i = d; i < arr_len; i++)
        {
            temp = arr[i];
            for(j = i; j >= d; j -= d)
            {
                if(temp < arr[j - d])
                    {
                        arr[j] = arr[j - d];
                    }
                else break;
            }
            arr[j] = temp;  
        }
	}
    return 0;
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