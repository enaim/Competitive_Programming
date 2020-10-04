#include <bits/stdc++.h>
using namespace std;

struct node{
    ll prb,penalty,m,sub[70];
};

node ar[110];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,n,l,r,pen,j,x,last;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            scanf("%lld",&ar[x].prb);
            scanf("%lld",&ar[x].penalty);
            scanf("%lld",&ar[x].m);
            for(j=0;j<ar[x].m;j++)
                scanf("%lld",&ar[x].sub[j]);
        }

        int flag = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(flag)
                continue;
            if(i==0)
            {
                last = x;
                for(j=0;j<ar[x].m;j++)
                    ar[x].penalty+=ar[x].sub[j],ar[x].prb++;
                continue;
            }

            if((ar[last].prb<ar[x].prb) || (ar[last].prb==ar[x].prb && ar[last].penalty>ar[x].penalty))
            {
                flag = 1;
                continue;
            }

            pen = ar[x].penalty;
            ll pr = ar[x].prb;
            l = r = 0;
            for(j=0;j<ar[x].m;j++)
            {
                if(ar[last].prb==ar[x].prb)
                    break;
                ar[x].penalty+=ar[x].sub[j],ar[x].prb++;
                r = j;
            }

            if(ar[last].prb==ar[x].prb && ar[x].penalty<ar[last].penalty)
            {
                ar[x].penalty = pen;
                ar[x].prb = pr;
                for(j=0;j<ar[x].m;j++)
                {
                    if(ar[last].prb-1==ar[x].prb)
                        break;
                    ar[x].penalty+=ar[x].sub[j],ar[x].prb++;
                }
            }
            last = x;
        }
        if(flag)
            printf("Case %d: Say no to rumour >:\n",ks++);
        else
            printf("Case %d: We respect our judges :)\n",ks++);
    }

    return 0;
}
