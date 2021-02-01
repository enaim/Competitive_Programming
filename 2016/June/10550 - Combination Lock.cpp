#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,b,c,d,ans;

    while((4==scanf("%d%d%d%d",&a,&b,&c,&d)  && ( a || b || c || d)))
    {
        ans=1080;

        if(a<b)
            ans+=(40+a-b)*9;
        else
            ans+=(a-b)*9;
        if(b>c)
            ans+=(40+c-b)*9;
        else
            ans+=(c-b)*9;
        if(c<d)
            ans+=(40+c-d)*9;
        else
            ans+=(c-d)*9;

        printf("%d\n",ans);
    }

    return 0;
}

