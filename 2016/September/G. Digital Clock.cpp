#include<stdio.h>


int main()
{
    int tks,h,m,H,M,past;
    int ar[100];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d%d",&h,&m,&H,&M);

        int x = h*60 + m;
        int y = H*60 + M;
        int z = 12*60;

        int past = ((x%z) - (y%z) + z) % z;

        printf("%d %d\n",past/60,past%60);
    }

    return 0;
}

