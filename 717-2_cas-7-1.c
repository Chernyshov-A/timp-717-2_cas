#include "stdio.h"
int part(int* a, int l, int r) 
   {
       int tmp,ptr = l;
       for ( int i = l; i <= r; i++ ) 
       {
           if ( a[r] > a[i] ) // все элементы в правую / левую сторону
           {
               tmp = a[ptr];
               a[ptr] = a[i];
               a[i] = tmp;
               ptr += 1;
           }
       }

       tmp = a[ptr]; // обмен 
       a[ptr] = a[r];
       a[r] = tmp; 

       return ptr;
   }


void sorting_function(int* a, int l, int r)
   {
       if(r<=l)return;
       int i = part(a, l, r);
       sorting_function (a, l, i-1);
       sorting_function (a, i+1, r);
   }


int printing_function(int *a,int arr_len)
    {
        for(int i = 0; i < arr_len; i++)
        {
            if(i<arr_len-1)
            {
                printf("%d ",a[i]);
            }else
            {
                printf("%d",a[i]);
            }
        }
        printf("\n");
        return 0;
    }

int main()
{
    int n;
    scanf("%d",&n);
    int array[n];
    for(int i = 0; i< n; i++)
    {
        scanf("%d",&array[i]);
    }
    sorting_function(array,0,n-1);
    printing_function(array,n);
}