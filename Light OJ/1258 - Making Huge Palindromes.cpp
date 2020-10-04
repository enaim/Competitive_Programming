#include <stdio.h>
#include <string.h>

char Text[1000010];
char Pattern[1000010];
int Prefix[1000010];
int j;

void Compute_Prefix_Function(int n)
{
    int i,j;
    j = 0;
    Prefix[0]=0;
    for(i=1;i<n;i++)
    {
        while((j>0) && (Pattern[j] != Pattern[i]))
            j = Prefix[j-1];

        if(Pattern[j] == Pattern[i])
            j = j + 1;

        Prefix[i]=j;
    }
}

void KMP(int n)
{
    int i;
    j = 0;
    for(i=0;i<n;i++)
    {
        while((j>0) && (Pattern[j] != Text[i]))
            j = Prefix[j-1];

        if(Pattern[j]==Text[i])
            j = j + 1;
        else
            j = Prefix[j];
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,n;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",Text);
        n = strlen(Text);
        int i = 0;
        while(i<=n/2)
        {
            Pattern[i] = Text[n-i-1];
            Pattern[n-i-1] = Text[i];
            i++;
        }
        Pattern[n]='\0';
        Compute_Prefix_Function(n);
        KMP(n);
        printf("Case %d: %d\n",ks++,n+(n-j));
    }

    return 0;
}
