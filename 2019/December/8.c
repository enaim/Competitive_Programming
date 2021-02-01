#include<stdio.h>

void Reverse(int n,int ar[])
{
    int i,temp;
    for(i=0;i<n/2;i++)
    {
        temp = ar[i];
        ar[i] = ar[n-i-1];
        ar[n-i-1] = temp;
    }
    return;
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

    Reverse(n,ar);

    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    printf("\n");

    return 0;
}
