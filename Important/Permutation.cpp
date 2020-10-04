#include<stdio.h>
#include<string.h>

int n;
int Q[20];
char str[20];
bool vis[20];

void go(int depth)
{
    int i,j;
    if(depth==n+1)
    {
        for(i=1;i<=depth-1;i++)
            printf("%c",str[Q[i]]);
        printf("\n");
        return;
    }

    char pre[12],cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=1;j<depth;j++)
            if(Q[j]==i)
                break;
        if(j!=depth)
            continue;

        for(j=0;j<cnt;j++)
            if(str[i]==pre[j])
                break;
        if(j!=cnt)
            continue;

        if(vis[i]==false)
        {
            vis[i]=true;
            Q[depth] = i;
            go(depth+1);
            vis[i]=false;
            pre[cnt++]=str[i];
        }
    }
}

int main()
{
    while(scanf("%s",str)==1)
    {
        n = strlen(str);
        go(1);
        printf("\n");
    }
    return 0;
}
