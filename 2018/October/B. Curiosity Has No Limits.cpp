#include<bits/stdc++.h>
using namespace std;

int arr[200010],n;
int ar[100010],br[100010];

int go(int k,int l)
{
    if(l==n-1)
    {
        return 1;
    }
    int i;
    for(i=0;i<4;i++)
    {
        if((i | k) == ar[l] && ( i & k )==br[l])
        {
            int x = go(i,l+1);
            if(x==1)
            {
                arr[l]=i;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int i,j,k,l,t,x;
    vector<int>v;

    scanf("%d",&n);

    for(i=0;i<n-1;i++)
        scanf("%d",&ar[i]);
    for(i=0;i<n-1;i++)
        scanf("%d",&br[i]);

    for(i=0;i<4;i++)
    {
        x = go(i,0);
        if(x)
            break;
    }
    if(x==0)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    cout<<i<<" ";
    for(i=0;i<n-1;i++)
        printf("%d ",arr[i]);
    return 0;
}
