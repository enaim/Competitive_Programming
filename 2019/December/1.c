#include<stdio.h>

void Print(int n)
{
    printf("The number is -> %d\n",n);
    return;
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d",&n);

    Print(n);

    return 0;
}
