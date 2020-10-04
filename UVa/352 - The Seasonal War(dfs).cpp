#include <stdio.h>
#include <string.h>
#include <math.h>

const int Size = 25;

char ar[Size][Size];
int flag[Size][Size];
int n;

void graph_travers(int r,int c)
{
    int o,p;

    for(o=r-1;o<r+2;o++)
        for(p=c-1;p<c+2;p++)
            if(o>=0 && p>=0 && o<n && p<n)
                if(ar[o][p]=='1' && flag[o][p] == true)
                {
                    flag[o][p]=false;
                    graph_travers(o,p);
                }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,r=1;
    int cnt;

    while(1==scanf("%d",&n))
    {
        cnt=0;
        for(i=0;i<n;i++)
            scanf("%s",ar[i]);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                flag[i][j]=true;

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(ar[i][j]=='1' && flag[i][j]==true)
                {
                    cnt++;
                    graph_travers(i,j);
                }
        printf("Image number %d contains %d war eagles.\n",r++,cnt);
    }

    return 0;
}


