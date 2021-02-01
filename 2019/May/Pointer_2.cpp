#include<stdio.h>
#include<stdlib.h>
#include<iostream>


int main()
{
    int i;
    int *ar;
    ar = (int*)malloc(sizeof(int)*5);

//    for(i=0;i<5;i++)
//        scanf("%d",&ar[i]);

    for(i=0;i<5;i++)
        ar[i]=i;
    for(i=0;i<5;i++)
        printf("%d ",ar[i]);
    printf("\n");

    int *arr;
    arr = new int[5];

    for(i=0;i<5;i++)
        arr[i]=i+10;
    for(i=0;i<5;i++)
        printf("%d ",arr[i]);
    printf("\n");

    int ar1[10],*p;
    p = ar1;    /// Array doesn't need & operator
    for(i=0;i<5;i++)
        ar1[i]=3*i;
    for(i=0;i<5;i++)
        printf("%d ",*(p+i));
    printf("\n");

    return 0;
}
