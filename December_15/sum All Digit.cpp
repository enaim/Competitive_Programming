#include<stdio.h>
#include<math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int a,sum,n;
    while(1==scanf("%d",&n))
    {
        sum=0;

        while(0<n || n<0)
        {
            a=n%10;
            printf("a -> %d\n",a);
            n/=10;
            sum+=a;
        }
        printf("sum -> %d\n",sum);
    }

    return 0;
}

