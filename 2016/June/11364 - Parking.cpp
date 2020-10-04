#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,mn,mx,a,n,i,ans;
    scanf("%d",&tks);
    while(tks--)
    {
        mn = 100;
        mx=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(mx<a)
                mx = a;
            if(mn>a)
                mn=a;
        }

        ans = (mx - mn) * 2 ;

        printf("%d\n",ans);
    }


    return 0;
}


