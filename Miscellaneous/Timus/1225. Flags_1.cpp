#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std;

int main()
{
    long long n,res,i,x,a,b,temp;
    while(1==scanf("%lld",&n))
    {
        if(n==1)
            printf("2\n");
        else
        {
            a=2;
            b=0;
            temp=0;
            for(i=2;i<=n;i++)
            {
                temp=a;
                a = a+b;
                b=temp;
            }
            printf("%lld\n",a);
        }
    }

    return 0;
}
