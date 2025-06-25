#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    int ar[110],lis[110];
    while(1==scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&ar[i]);
        lis[0]=1;
        for(int i=1;i<n;i++)
        {
            lis[i]=1;
            for(int j=0;j<i;j++)
            {
                if(ar[i]>ar[j] && lis[i]<lis[j]+1)
                    lis[i]=lis[j]+1;
            }
        }
        int mx = 0;
        for(int i=0;i<n;i++)
            mx = max(mx,lis[i]);
        printf("Longest Increasing Subsequence Length - > %d\n", mx);
    }

    return 0;
}
