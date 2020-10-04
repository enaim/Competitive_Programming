#include <stdio.h>
#include <string.h>
#include <math.h>


const int siz=25;
int colour[siz][siz];
int dis[siz][siz];
int cnt[siz];
int Queue[siz];

int Risk(int a,int b)
{
    int Front,Rare,i,j;

    Front = Rare = 0;
    Queue[Rare++] = a;

    while(Front < Rare)
    {
        a=Queue[Front++];
        for(i=1;i<=20;i++)
        {
            if(dis[a][i]==1 && colour[a][i]==true)
            {
                Queue[Rare++] = i;
                cnt[i]=cnt[a]+1;
                if(i==b)
                    return cnt[i];
                for(j=1;j<=20;j++)
                    colour[j][i] = false;
            }
            colour[i][a]=false;
        }
    }
}

void New()
{
    int i,j;
    memset(cnt,0,sizeof cnt);
    for(i=1;i<=20;i++)
        for(j=1;j<=20;j++)
            colour[i][j]=true;

}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int A,B,r,i,j,N,x,k,T=1;

    for(i=0;i<25;i++)
        for(j=0;j<25;j++)
            colour[i][j]=true;

    while(1==scanf("%d",&j))
    {
        memset(dis,0,sizeof dis);
        memset(cnt,0,sizeof cnt);
        r=1;
        while(r<20)
        {
            if(r != 1)
                scanf("%d",&j);
            for(i=0;i<j;i++)
            {
                scanf("%d",&k);
                dis[r][k] = dis[k][r] = 1;
            }
            r++;
        }

        printf("Test Set #%d\n",T);
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%d%d",&A,&B);
            x = Risk(A,B);
            printf("%2d to %2d:%2d\n",A,B,x);
            New();
        }
        T++;
        printf("\n");
    }
    return 0;
}

