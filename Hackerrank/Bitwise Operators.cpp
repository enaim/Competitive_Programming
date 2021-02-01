#include <stdio.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,k,i,j,mx1,mx2,mx3;
    scanf("%d%d",&n,&k);
    mx1 = 0;
    mx2 = 0;
    mx3 = 0;
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        {
            if((i&j)>=mx1 && (i&j)<k)
                mx1 = (i&j);
            if((i|j)>=mx2 && (i|j)<k)
                mx2 = (i|j);
            if((i^j)>=mx3 && (i^j)<k)
                mx3 = (i^j);
        }

    printf("%d\n%d\n%d\n",mx1,mx2,mx3);

    return 0;
}
