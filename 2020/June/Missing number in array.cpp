#include <bits/stdc++.h>
using namespace std;

int main() {
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        long long i,n,val,sum = 0;
        scanf("%lld",&n);
        for(i=0;i<n-1;i++)
        {
            scanf("%lld",&val);
            sum+=val;
        }
        printf("%lld\n",((n*(n+1LL))/2LL)-sum);
    }

	return 0;
}
