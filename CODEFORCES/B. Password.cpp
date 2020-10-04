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

    int i,m,n,mx;
    while(1==scanf("%s",Pattern))
    {
        m = strlen(Pattern);
        Compute_Prefix_Function(m);
        mx = 0;
        for(i=0;i<m-1;i++)
            mx = max(mx,Prefix[i]);

        while(Prefix[m-1]>mx)
            Prefix[m-1] = Prefix[Prefix[m-1]-1];
        mx = Prefix[m-1];
        Pattern[mx] = '\0';

        if(mx)
            printf("%s\n",Pattern);
        else
            printf("Just a legend\n");
    }

    return 0;
}
