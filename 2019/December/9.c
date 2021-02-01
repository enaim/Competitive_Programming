#include<stdio.h>

int SumOfArray(int n,int ar[])
{
    int i,sum=0;
    for(i=0;i<n;i++)
        sum += ar[i];
    return sum;
}

int main()
{
    int i,n;
    int ar[100];

    printf("Enter the number of element of array: ");
    scanf("%d",&n);

    printf("Enter the elements of array: ");
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);

    int sum = SumOfArray(n,ar);

    printf("Summation of array is = %d\n",sum);

    return 0;
}
