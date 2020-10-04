#include<stdio.h>
#include<math.h>


int main()
{
    long long a,b,c;
    while(2==scanf("%lld%lld",&a,&b))
    {
        if(a>b)
            printf("%lld\n",a-b);

        else
        printf("%lld\n",b-a);
    }

    return 0;
}
