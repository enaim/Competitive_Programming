#include<bits/stdc++.h>
using namespace std;

char Text[1000010];
char Pattern[1000010];
int Prefix[1000010];
vector<int>vec;

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
                vec.push_back(i-m+2);
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

    int m,n,ks=1,tks,i;
    scanf("%d",&tks);
    while(tks--)
    {
        if(ks!=1)
            printf("\n");
        ks++;
        vec.clear();
        scanf("%s%s",Text,Pattern);
        n = strlen(Text);
        m = strlen(Pattern);
        Compute_Prefix_Function(m);
        KMP(m,n);
        int sz = vec.size();
        if(sz==0)
            printf("Not Found");
        else
            printf("%d\n",sz);
        for(i=0;i<sz;i++)
        {
            if(i==0)
                printf("%d",vec[i]);
            else
                printf(" %d",vec[i]);
        }
        printf("\n");
    }

    return 0;
}
