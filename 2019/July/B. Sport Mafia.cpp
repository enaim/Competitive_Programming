#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long x,n,k,i;
    while(scanf("%lld%lld",&n,&k)==2)
    {
        for(i=1;i<=1000000;i++)
        {
            x =  (i*(i+1))/2LL;
            if(n-i==x-k)
                break;
        }
        cout<<x-k<<endl;
    }

    return 0;
}
