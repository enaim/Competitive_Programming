#include <stdio.h>
#include <string.h>
#include <math.h>


int ar[100],Front,Rare;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i,v;
    Front = -1;
    Rare = -1;
    while(1==scanf("%d",&n))
    {
        if(n==1)
        {
            scanf("%d",&v);
            ar[++Rare] = v;
        }
        else if(n==2)
        {   if(Front == Rare)
                printf("Overflow\n");
            else
                Rare--;
        }
        else if(n==3)
        {
            if(Front == Rare)
                printf("Overflow\n");
            else
            {
                printf("Rare  : %d\n",ar[Rare]);
            }
        }
    }

    return 0;
}

