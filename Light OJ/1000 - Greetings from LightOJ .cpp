#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,a,b;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&a,&b);
        printf("Case %d: %d\n",ks++,a+b);
    }

    return 0;
}
