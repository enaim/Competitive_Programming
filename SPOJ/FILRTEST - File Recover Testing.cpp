#include<bits/stdc++.h>
using namespace std;

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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int m,n,ans,rep,len;
    while(2==scanf("%d%s",&len,Pattern) && len != -1)
    {
        m = strlen(Pattern);
        Compute_Prefix_Function(m);
        rep = m - Prefix[m-1];
        ans = 1;
        ans += (len-m)/rep;
        if(len<m)
            printf("0\n");
        else
            printf("%d\n",ans);
    }

    return 0;
}
