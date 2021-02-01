#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,cnt,n,x;
    scanf("%d",&tks);
    while(tks--)
    {
        cnt=0;
        scanf("%d",&n);

        x=n/100;
        n = n%100;
        cnt+=x;
        x=n/50;
        n = n%50;
        cnt+=x;
        x=n/10;
        n = n%10;
        cnt+=x;
        x=n/5;
        n = n%5;
        cnt+=x;
        x=n/2;
        n = n%2;
        cnt+=x;
        x=n/1;
        n = n%1;
        cnt+=x;

        printf("%d\n",cnt);
    }

    return 0;
}
