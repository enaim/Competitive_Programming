#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{
    ll p,g;
};
node ar[100010];
ll sum[100010];
ll gold[100010];
ll space[100010];

bool compare(node a,node b)
{
    return a.p<b.p;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ll s,b;
    int i,val,l,r,mid;

    while(scanf("%lld%lld",&s,&b)==2)
    {
        for(i=0;i<s;i++)
            scanf("%lld",&space[i]);
        for(i=0;i<b;i++)
            scanf("%lld%lld",&ar[i].p,&ar[i].g);

        sort(&ar[0],&ar[b],compare);

        sum[0]=ar[0].p;
        gold[0]=ar[0].g;
        for(i=1;i<b;i++)
            sum[i] = ar[i].p ,gold[i] = ar[i].g+gold[i-1];
        for(i=0;i<s;i++)
        {
            val = space[i];
            l = 0;
            r = b-1;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(sum[mid]>val)
                    r = mid-1;
                else
                    l = mid+1;
            }
            if(i==0)
                printf("%lld",gold[l-1]);
            else
                printf(" %lld",gold[l-1]);
        }
        printf("\n");
    }

    return 0;
}
