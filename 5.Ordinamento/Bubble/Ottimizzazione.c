#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int a[5]={3,5,-2,1,11};

     printf("\nNon ordinata");
    for(int i=0; i<5; i++)
    {
        printf("\t%d",a[i]);
    }


    int lastSwap= (sizeof(a) / sizeof(a[0]))-1; //Replace with N-1

    for(int i=1; (i<sizeof(a) / sizeof(a[0]))/*Replace with N-1*/; i++)
    {
        bool is_sorted=true;
        int currentSwap = -1;

            for(int j=0; j < lastSwap; j++)
            {
                    if(a[j] > a[j+1])
                    {
                     int temp = a[j];
                     a[j] = a[j+1];
                     a[j+1] = temp;
                     is_sorted = false;
                     currentSwap = j;
                    }
            }
            if(is_sorted) break;
            lastSwap = currentSwap;

    }


    printf("\nOrdinata");
    for(int i=0; i<5; i++)
    {
        printf("\t%d",a[i]);
    }


    return 0;
}
