#include<bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);
    freopen("raw.txt","w",stdout);

    printf("100\n");
    for(int j = 1;j<=10;j++)
    {
        for(int i=0;i<1000;i++)
            if(i%2==0)
                printf("M");
            else
                printf("R");
        printf("\n");
    }

    for(int j=1;j<=25;j++)
    {
        for(int i=0;i<1000/3;i++)
            if(i%2==0)
                printf("MMM");
            else
                printf("RRR");
        printf("\n");
    }

    for(int j = 1;j<=25;j++)
    {
        for(int i=0;i<1000;i++)
                printf("M");
        printf("\n");
    }

    for(int j = 1;j<=25;j++)
    {
        for(int i=0;i<1000;i++)
                printf("R");
        printf("\n");
    }
    printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRMRMRRMRMRMRMRMRMRMRMRMRMR\n");
    printf("MMMMRMRRRRMMMMR\n");
    printf("RRRRMMRRMMMRR\n");
    printf("MRMRMRMRMRMRMMMMMMMMRRRRRR\n");
    printf("MRMMMRRR\n");
    printf("MRMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    printf("MRMRRRRRRRRRRRRRRRRRRRRRRRRRR\n");
    printf("MMMMMMMMMMMM\n");
    printf("MMMMMM\n");
    printf("RRRM\n");
    printf("M\n");
    printf("R\n");
    printf("RMRMRRMRMRMRRMRMRMRMRRM\n");
    printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    printf("RRRRRRRRRRMM\n");

    return 0;
}
