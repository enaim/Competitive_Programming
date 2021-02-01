#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int a,b,r,t;
    scanf("%d",&t);
    r = 0;
    while(r<t)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",a+b);
        r++;

    }

    return 0;
}
