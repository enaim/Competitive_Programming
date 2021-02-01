#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,m,n,x,male;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&m,&n);

        x = m*n;

        male = x /2;

        if(x % 2 == 0)
            printf("%d\n",male);
        else
            printf("%d\n",male+1);
    }

    return 0;
}

