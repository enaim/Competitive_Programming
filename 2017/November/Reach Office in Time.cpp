#include<bits/stdc++.h>
using namespace std;


struct office{
    int t,c;
};


bool compare(office a,office b)
{
    if(a.c==b.c)
        return a.t<b.t;
    return a.c<b.c;
}

int main()
{
//    freopen("in.txt","r",stdin);

    int n,rem,i;
    office ar[20],br[20];
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i].t);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i].c);
        scanf("%d",&rem);

        rem-=15;

        int cnt = 0;
        for(i=0;i<n;i++)
        {
            if(ar[i].t<=rem)
            {
                br[cnt].c = ar[i].c;
                br[cnt].t = ar[i].t;
                cnt++;
            }
        }
        printf("OPTIONS TO REACH OFFICE TIMELY ARE:\n");
        for(i=0;i<cnt;i++)
        {
            if(i==0)
                printf("%d",br[i].t);
            else
                printf(" %d",br[i].t);
        }
        printf("\n");

        for(i=0;i<cnt;i++)
        {
            if(i==0)
                printf("%d",br[i].c);
            else
                printf(" %d",br[i].c);
        }
        printf("\n");
        sort(&br[0],&br[cnt],compare);

        printf("Best Option:\n");
        printf("%d\n%d\n",br[0].t,br[0].c);
    }

    return 0;
}
