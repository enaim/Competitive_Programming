#include<bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);

    char str[30][30];
    int ar[30];
    int i,j,r,c,x,p,q,sum,m,n;
    int tks,ks=1;

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d%d",&r,&c,&m,&n);
        memset(ar,0,sizeof ar);

        for(i=0;i<r;i++)
            scanf("%s",str[i]);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                x = str[i][j]-'A';
                ar[x]++;
            }
        sort(&ar[0],&ar[26]);
        x = 24;
        p = ar[25];
        while(ar[25] == ar[x])
        {
            p+=ar[25];
            x--;
        }
        q = (r*c)-p;
        sum = (p*m)+(q*n);
        printf("Case %d: %d\n",ks++,sum);
    }

    return 0;
}
