#include<bits/stdc++.h>
using namespace std;


int main()
{
    int tks,ks=1;
    int d;
    double n;
    long long m;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&m);
        n = m;
        n = pow(n,1.0/3.0);
        int x = n;
        if(((x+1)*(x+1)*(x+1)) <= m)
            x++;

        printf("%d\n",x);
    }

    return 0;
}
