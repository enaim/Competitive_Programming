#include<bits/stdc++.h>
using namespace std;


int main()
{
    int ans,a,b,c,s;
    while(4==scanf("%d%d%d%d",&s,&a,&b,&c) && (s || a || b || c))
    {
        ans = 40*3;
        if(a>=s)
            ans += (40+s-a);
        else
            ans += (s-a);

        if(a>=b)
            ans += (40+b-a);
        else
            ans += (b-a);

        s = b;
        a = c;
        if(a>=s)
            ans += (40+s-a);
        else
            ans += (s-a);

        printf("%d\n",ans*9);
    }

    return 0;
}
