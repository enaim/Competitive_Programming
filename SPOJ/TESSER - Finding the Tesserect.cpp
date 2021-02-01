#include<bits/stdc++.h>
using namespace std;

int Text[100010];
char Pattern[100010];
int Prefix[100010];

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
    for(i=1;i<n;i++)
    {
        while(j>0)
        {
            if(Pattern[j] == 'G' && Text[i-1]>=Text[i])
                j = Prefix[j-1];
            else if(Pattern[j] == 'L' && Text[i-1]<=Text[i])
                j = Prefix[j-1];
            else if(Pattern[j] == 'E' && Text[i-1]!=Text[i])
                j = Prefix[j-1];
            else break;
        }

        if((Pattern[j] == 'G' && Text[i-1]<Text[i]) || (Pattern[j] == 'L' && Text[i-1]>Text[i])
           || (Pattern[j] == 'E' && Text[i-1]==Text[i]))
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

    int m,n,tks,i;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&Text[i]);
        scanf("%s",Pattern);

        m = strlen(Pattern);
        Compute_Prefix_Function(m);

        if(KMP(m,n))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
