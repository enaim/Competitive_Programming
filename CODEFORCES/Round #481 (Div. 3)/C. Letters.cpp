#include<bits/stdc++.h>
using namespace std;

struct node{
    long long x,y;
};

node ar[200010];

int main()
{
    long long i,k,n,m,xa,xz;

    ar[0].x = 0;
    ar[0].y = 0;
    scanf("%lld%lld",&n,&m);

    for(i=1;i<=n;i++)
    {
        scanf("%lld",&xa);
        ar[i].x = ar[i-1].y+1;
        ar[i].y = ar[i-1].y+xa;
    }
    k = 1;
    for(i=1;i<=m;i++)
    {
        scanf("%lld",&xa);
        xz = 1;
        while(xz && k<=n)
        {
            if(ar[k].y >=xa)
            {
                cout<<k<<" "<<xa-ar[k-1].y<<endl;
                xz = 0;
            }
            else
                k++;
        }
    }

    return 0;
}
