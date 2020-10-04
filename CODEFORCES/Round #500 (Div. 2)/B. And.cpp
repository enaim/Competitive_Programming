#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,ans,i,j,z,n,a,b;

    scanf("%d%d",&n,&x);

    int ar[100010];
    int br[100010];
    map<int,int>mp1,mp2;

    z = 0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
        br[i] = ar[i]&x;
        mp2[br[i]]++;
        mp1[ar[i]]++;
        if(mp1[ar[i]]>1)
            z = 1;
    }
    if(z)
    {
        printf("0\n");
        return 0;
    }

    for(i=0;i<n;i++)
    {
        mp1[ar[i]]--;
        mp2[br[i]]--;
        if(mp1[br[i]]>0)
        {
            printf("1\n");
            return 0;
        }
        if(mp2[ar[i]]>0)
        {
            printf("1\n");
            return 0;
        }
        mp1[ar[i]]++;
        mp2[br[i]]++;
    }

    for(i=0;i<n;i++)
    {
        mp1[ar[i]]--;
        mp2[br[i]]--;
        if(mp2[br[i]]>0)
        {

            printf("2\n");
            return 0;
        }
        mp1[ar[i]]++;
        mp2[br[i]]++;
    }
    printf("-1\n");

    return 0;
}
