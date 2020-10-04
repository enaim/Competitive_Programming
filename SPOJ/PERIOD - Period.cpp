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

    int m,n,i,ind,tks,ks=1,k,last;
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Test case #%d\n",ks++);
        scanf("%d%s",&m,Pattern);
        Compute_Prefix_Function(m);
        k = m;
        last = 0;
        for(i=0;i<m;i++)
        {
            k = i+1;
            if(k%(k-Prefix[i])==0 && k/(k-Prefix[i])>1)
                printf("%d %d\n",k,(k/(k-Prefix[i])));
        }
    }

    return 0;
}
