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
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",str);
        n = strlen(str);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(str[j]>str[j+1])
                {
                    char temp = str[j];
                    str[j]=str[j+1];
                    str[j+1]=temp;
                }
            }
        }
        go(1);
        printf("\n");
    }
    return 0;
}
