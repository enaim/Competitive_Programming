#include <stdio.h>
#include <string.h>

char Text[100010];
char Pattern[1010];
int Prefix[1010];

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

bool KMP(int m,int n)
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
                return true;
        }
        else
            j = Prefix[j];
    }
    return false;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int m,n,tks,q;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",Text);
        n = strlen(Text);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%s",Pattern);
            m = strlen(Pattern);
            Compute_Prefix_Function(m);
            if(KMP(m,n))
                printf("y\n");
            else
                printf("n\n");
        }
    }

    return 0;
}
