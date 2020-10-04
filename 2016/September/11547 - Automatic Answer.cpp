#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,n,ans;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);

        ans = (((n*63)+7492)*5)-498;
        ans = (ans/10)%10;

        if(ans<0)
            printf("%d\n",ans*(-1));
        else
            printf("%d\n",ans);
    }

    return 0;
}
