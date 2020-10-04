#include<bits/stdc++.h>
using namespace std;

char Text[100010];
char Pattern[100010];
int Prefix[100010];
int ind;

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
            ind = j;
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
    while(1==scanf("%s",Text))
    {
        int i = 0;
        n = strlen(Text);
        while(i<=n/2)
        {
            Pattern[i] = Text[n-i-1];
            Pattern[n-i-1] = Text[i];
            i++;
        }
        Pattern[n]='\0';
        m = n;
        Compute_Prefix_Function(m);
        KMP(m,n);
        printf("%s",Text);
        for(i=ind;i<m;i++)
            printf("%c",Pattern[i]);
        printf("\n");
    }

    return 0;
}
