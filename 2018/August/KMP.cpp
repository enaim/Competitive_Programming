#include<bits/stdc++.h>
using namespace std;

char Text[1000010];
char Pattern[1000010];
int Prefix[1000010];

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
                printf("Pattern found form index - > %d\n",i-m+1);
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

    int m,n;
    while(2==scanf("%s%s",Text,Pattern))
    {
        n = strlen(Text);
        m = strlen(Pattern);
        Compute_Prefix_Function(m);
        KMP(m,n);
    }

    return 0;
}
