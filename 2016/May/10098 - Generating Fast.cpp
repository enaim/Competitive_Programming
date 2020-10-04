#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

int len,k=1;
int Q[15];
char ar[15];


void fact(int depth)
{
    int x,m;
    int store[15];

    if(depth == len)
    {
        for(int i=0;i<len;i++)
            printf("%c",ar[Q[i]]);
        printf("\n");
        return;
    }

    char pre[11];
    int cnt=0;

    for(int i=0;i<len;i++)
    {
        bool isProcessable = true;

        for(int j=0;j<depth;j++)
            if(Q[j]==i)
            {
                isProcessable = false;
                break;
            }

        for(int j=0;j<cnt;j++)
            if(pre[j] == ar[i])
            {
                isProcessable = false;
                break;
            }

        if(!isProcessable)  continue;

        pre[cnt++] = ar[i];
        Q[depth] = i;
        fact(depth+1);
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(Q,-1,sizeof Q);
        scanf("%s",ar);

        len = strlen(ar);
        sort(&ar[0],&ar[len]);
        fact(0);
        printf("\n");
    }

    return 0;
}
