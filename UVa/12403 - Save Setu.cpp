#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char s[100];
    int tks,ks=1,ac,n,tk;
    while(1 == scanf("%d",&tks))
    {
        ac=0;
        while(tks--)
        {
            scanf("%s",s);
            if(s[0] == 'd')
            {
                scanf("%d",&tk);
                ac+=tk;
            }
            else
                printf("%d\n",ac);
        }
    }

    return 0;
}

