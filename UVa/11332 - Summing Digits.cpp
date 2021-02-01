#include<stdio.h>
#include<string.h>
#include<math.h>


int Add(int n)
{
    int sum,x;

    sum=0;
    while(n!=0)
    {
        x = n%10;
        n/=10;
        sum+=x;
    }

    return sum;
}


int main()
{
    int sum,x,n;

    while(1==scanf("%d",&n) && n)
    {
        sum=0;
        while(n!=0)
        {
            x = n%10;
            n/=10;
            sum+=x;
        }
        while(sum>9)
            sum = Add(sum);

        printf("%d\n",sum);
    }

    return 0;
}
