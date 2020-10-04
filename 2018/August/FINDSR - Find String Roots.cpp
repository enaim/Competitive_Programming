#include<bits/stdc++.h>
using namespace std;

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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,ind,m,n,ans;
    while(1==scanf("%s",Pattern))
    {
        if(Pattern[0]=='*')
            break;
        m = strlen(Pattern);
        Compute_Prefix_Function(m);
        int x = m-Prefix[m-1];
        if(m%x!=0)
            printf("1\n");
        else
            printf("%d\n",m/x);
    }

    return 0;
}
