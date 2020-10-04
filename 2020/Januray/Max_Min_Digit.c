#include<stdio.h>


int main()
{
    int n,i,mx,mn,cnt = 0,temp;
    int digits[20];

    printf("Enter a number: ");
    scanf("%d",&n);

    temp = n;
    while(n!=0)
    {
        digits[cnt]=n%10;
        cnt++;
        n = n/10;
    }
    n = temp;

    mn = digits[0];
    for(i=1;i<cnt;i++)
    {
        if(mn>digits[i])
        {
            mn = digits[i];
        }
    }
    printf("Minimum digit of integer %d is - > %d\n",n,mn);

    mx = digits[0];
    for(i=1;i<cnt;i++)
    {
        if(mx<digits[i])
        {
            mx = digits[i];
        }
    }
    printf("Maximum digit of integer %d is - > %d\n",n,mx);

    return 0;
}
