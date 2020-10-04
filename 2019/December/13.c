#include<stdio.h>

int Reverse(int n)
{
    int rev = 0;

    while(n!=0)
    {
        rev = (rev * 10) + (n%10);
        n = n / 10;
    }

    return rev;
}

int Append(int a,int b)
{
    b = Reverse(b);

    while(b!=0)
    {
        a = a*10 + b%10;
        b/=10;
    }
    return a;
}

int main()
{
    int a,b;

    printf("Enter two integers: ");
    scanf("%d%d",&a,&b);

    a = Append(a,b);

    printf("Both numbers after appending operation: %d %d\n",a,b);

    return 0;
}
