#include<stdio.h>
#include<math.h>

int main()
{
    long long a,b,c,d,i,n;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);


        if (a+b+c<=d || b+c+d<=a || c+d+a<=b || d+a+b<=c)
            printf("banana\n");
        else if(a==b && b==c && c==d)
            printf("square\n");
        else if((a==c && b==d) || (a==b && c==d) || (a==d && b==c))
            printf("rectangle\n");
        else
            printf("quadrangle\n");

    }

    return 0;
}
