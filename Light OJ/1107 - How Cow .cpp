#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int x1,y1,x2,y2,x,y,T;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

        scanf("%d",&T);
        while(T--)
        {
            scanf("%d%d%",&x,&y);

            if(x >= x1 && y>= y1 && x<=x2 && y<=y2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}


