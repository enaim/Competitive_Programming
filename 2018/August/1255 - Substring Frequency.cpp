#include <stdio.h>
#include <string.h>

char Text[1000010];
char Pattern[1000010];
int Prefix[1000010];
int cnt;

void Compute_Prefix_Function(int m)
{
    int i,j;
    j = 0;
    Prefix[0]=0;
    for(i=1;i<m;i++)
    {
        while((j>0) && (Pattern[j] != Pattern[i]))
            j = Prefix[j-1];

        if(Pattern[j] == Pattern[i])
            j = j + 1;

        Prefix[i]=j;
    }
}

void KMP(int m,int n)
{
    int i,j;
    j = 0;
    for(i=0;i<n;i++)
    {
        while((j>0) && (Pattern[j] != Text[i]))
            j = Prefix[j-1];

        if(Pattern[j]==Text[i])
        {
            j = j + 1;
            if(j==m)
            {
                cnt++;
                j = Prefix[j-1];
            }
        }
        else
            j = Prefix[j];
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int m,n,ks=1,tks;
    scanf("%d",&tks);
    while(tks--)
    {
        cnt = 0;
        scanf("%s%s",Text,Pattern);
        n = strlen(Text);
        m = strlen(Pattern);
        Compute_Prefix_Function(m);
        KMP(m,n);
        printf("Case %d: %d\n",ks++,cnt);
    }

    return 0;
}
