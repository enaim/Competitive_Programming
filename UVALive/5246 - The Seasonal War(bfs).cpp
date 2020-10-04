#include <stdio.h>
#include <string.h>
#include <math.h>

const int Size = 25;

char ar[Size][Size];
int flag[Size][Size],Queue[2000];
int n;

void graph_travers(int r,int c)
{
    int Front,Rare;
    int o,p;

    Front = Rare = 0;
    Queue[Rare++]=r;
    Queue[Rare++]=c;
    flag[r][c]=false;

    while(Front < Rare)
    {
        r = Queue[Front];
        c = Queue[Front+1];
        Front+=2;

        for(o=r-1;o<r+2;o++)
            for(p=c-1;p<c+2;p++)
            {
//                if(!(o>=0 && p>=0 && o<n && p<n))
//                    continue;
                if(o<0 || p<0 || o>=n || p>=n)
                    continue;

                if(ar[o][p]=='1'  &&  flag[o][p] == true)
                {
                    flag[o][p]=false;
                    Queue[Rare++]=o;
                    Queue[Rare++]=p;
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
                    graph_travers(i,j);
                }
        printf("Image number %d contains %d war eagles.\n",r++,cnt);
    }

    return 0;
}


