#include <stdio.h>
#include <string.h>
#include <math.h>

int ar[13];
int q[7];
int n,r;

void lotto(int depth,int start)
{
    if(depth==6)
    {
        for(int i=0;i<6;i++)
        {
            if(i==5)
                printf("%d",q[i]);
            else
                printf("%d ",q[i]);
        }
        printf("\n");
        return;
    }

    for(int i=start;i<n;++i)
    {
        q[depth] = ar[i];
        lotto(depth+1,i+1);
    }
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,r=0;;

    while(1==scanf("%d",&n))
    {
        if(n==0)
            break;
        if(r>0)
            printf("\n");

        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        lotto(0,0);
        r++;
    }

    return 0;
}


