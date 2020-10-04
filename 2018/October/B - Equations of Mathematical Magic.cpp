#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long a,b,c,d,i,j,x,f,l,tks,v;

    scanf("%lld",&tks);
    while(tks--)
    {
        scanf("%lld",&a);
        for(i=0;i<40;i++)
        {
            if(pow(2,i)<=a && pow(2,i+1)>a)
            {
                break;
            }
        }
        v = pow(2,i+1);
        l  = pow(2,i+1)-1;
        f = pow(2,i);

        long long mid = (l+f)/2;
        if(f==a)
        {
            printf("2\n");
            continue;
        }
        if(l==a)
        {
            printf("%lld\n",v);
            continue;
        }

        while(l>f)
        {
            mid = (l+f)/2;
            if(mid==a)
                break;
            if(a>mid)
                f = mid;
            else
            {
                l = mid;
                v/=2;
             }
        }
        cout<<v/2<<endl;
    }

    return 0;
}
