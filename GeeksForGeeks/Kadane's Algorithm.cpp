#include <bits/stdc++.h>
using namespace std;

int ar[1000010];

int main() {
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        long long sum = 0,mx=-1e18;
        for(i=0;i<n;i++)
        {
            if(sum<0)
                sum = 0;
            sum+=ar[i];
            mx = max(sum,mx);
        }
        printf("%d\n",mx);
    }

	return 0;
}
