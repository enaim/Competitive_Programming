#include<bits/stdc++.h>
using namespace std;

int sum[1000010];

int main()
{
    int n,i,ans,x,z=0,sum1=0;
    int ar[3010];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
        sum[ar[i]]++;
        sum1+=ar[i];
    }
    sort(&ar[0],&ar[n]);
    for(i=0;i<n;i++)
    {
        z = ar[i];
        while(sum[z]>1)
        {
            x = z;
            while(sum[x]!=0)
                x++;
            sum[x]++;
            sum[z]--;
        }
    }
    ans = 0;
    for(i=1;i<=1000000;i++)
    {
        if(sum[i])
            ans+=i;
    }
    cout<<ans-sum1<<endl;

    return 0;
}
