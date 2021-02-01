#include <stdio.h>
#include <string.h>
#include <math.h>

const int Size = 25;

char ar[Size][Size];
int flag[Size][Size];
int n;

struct Vartex
{
    int row;
    int clmn;
};

Vartex getVartex(int r,int c)
{
    Vartex ret;
    ret.row = r;
    ret.clmn = c;
    return ret;
}

Vartex Queue[Size*Size];

void graph_travers(Vartex r)
{
    int Front,Rare;
    int o,p;

    Front = Rare = 0;
    Queue[Rare++] = r;
    flag[r.row][r.clmn]=false;

    while(Front < Rare)
    {
        r = Queue[Front++];

        for(o=r.row-1;o<r.row+2;o++)
            for(p=r.clmn-1;p<r.clmn+2;p++)
            {
                if(o<0 || p<0 || o>=n || p>=n)
                    continue;

                if(ar[o][p]=='1'  &&  flag[o][p] == true)
                {
                    flag[o][p]=false;
                    Queue[Rare++]=getVartex(o,p);
                }
             }
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
            {
                if(ar[i][j]=='0')
                    flag[i][j]=false;
            }

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(flag[i][j]==true)
                {
                    cnt++;
                    graph_travers(getVartex(i,j));
                }
        printf("Image number %d contains %d war eagles.\n",r++,cnt);
    }

    return 0;
}

