#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);

    int i,n,m,z,ans,x,y;
    char a[1010],b[1010];

    while(1==scanf("%d",&n))
    {
        ans = 0;
        scanf("%s%s",a,b);
        for(i=0;i<n;i++)
        {
            x = a[i]-'0';
            y = b[i]-'0';
            z = abs(x-y);

            if(x>y)
            {
                m = 10-x+y;
            }
            else
            {
                m = 10-y+x;
            }
            if(z>m)
                ans+=m;
            else
                ans+=z;
        }
        printf("%d\n",ans);
    }

    return 0;
}
