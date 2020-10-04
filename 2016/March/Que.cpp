#include <stdio.h>
#include <string.h>
#include <math.h>



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i,v,Front,Rare;
    int ar[100];
    Front = 0;
    Rare = 0;
    while(1==scanf("%d",&n))
    {
        if(n==1)
        {
            scanf("%d",&v);
            ar[Rare] = v;
            Rare++;
        }
        else if(n==2)
        {   if(Front == Rare)
                printf("Underflow\n");
            else
                Front = Front + 1 ;
        }
        else if(n==3)
        {
            if(Front == Rare)
                printf("Underflow\n");
            else
                printf("Front : %d\n",ar[Front]);
        }
    }

    return 0;
}

