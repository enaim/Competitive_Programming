#include<stdio.h>
#include<math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,a;

    while(1==scanf("%d",&n))
    {
        while(0<n || 0>n)
        {
        a=n%10;
        printf("a -> %d\n",a);
        n/=10;
        }
    }

    return 0;
}
