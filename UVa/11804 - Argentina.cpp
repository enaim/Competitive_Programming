#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;


struct Argentina
{
    char name[25];
    char tmp[25];
    int atk;
    int dfn;
};

Argentina argentina[50];

bool compare(Argentina a , Argentina b)
{
    if(a.atk != b.atk)
        return a.atk > b.atk;
    if(a.atk == b.atk && a.dfn != b.dfn)
        return a.dfn < b.dfn;

    return 0 > strcmp(a.name,b.name);
}

bool compare2(Argentina c , Argentina d)
{
   return 1 > strcmp(c.name,d.name);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("in.output","w",stdout);

    int T,r,i,j;
    Argentina temp,f;

    scanf("%d",&T);

    r = 1;
    while(r<=T)
    {
        for(i=1;i<11;i++)
        {
            scanf("%s",argentina[i].name);
            scanf("%d",&argentina[i].atk);
            scanf("%d",&argentina[i].dfn);
        }

        sort(&argentina[1],&argentina[11],compare);
        sort(&argentina[1],&argentina[6],compare2);
        sort(&argentina[6],&argentina[11],compare2);

        printf("Case %d:\n(",r);

        for(i=1;i<11;i++)
        {
            printf("%s",argentina[i].name);

            if(i == 5 )
                printf(")\n(");
            else if(i == 10)
                printf(")\n");
            else
                printf(", ");
        }
        r++;
    }

    return 0;
}

