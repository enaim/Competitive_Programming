#include<bits/stdc++.h>
using namespace std;

char Pattern[110];
int Prefix[110];

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

    int m,n,i,ind,tks,ks=1;
    scanf("%d",&tks);
    gets(Pattern);
    while(tks--)
    {
        if(ks!=1)
            printf("\n");
        ks++;
        gets(Pattern);
        gets(Pattern);
        m = strlen(Pattern);
        Compute_Prefix_Function(m);
        for(i=m-1;i>=0;i--)
            if(Prefix[i]==0)
            {
                ind = i+1;
                break;
            }
        if(Prefix[m-1]>=m/2 && m%((Prefix[m-1]/ind)+1)==0)
            printf("%d\n",m/((Prefix[m-1]/ind)+1));
        else
            printf("%d\n",m);
    }

    return 0;
}
