#include<bits/stdc++.h>
using namespace std;

int ar[100];
int output[100];

void Radix_Sort(int exp,int n)
{
    int i;
    int cnt[10] = {0};
    for(i=0;i<n;i++)
        cnt[(ar[i]/exp)%10]++;
    for(i=1;i<10;i++)
        cnt[i]+=cnt[i-1];
    for(i=n-1;i>=0;i--)
    {
        output[cnt[(ar[i]/exp)%10]-1]=ar[i];
        cnt[(ar[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
        ar[i]=output[i];
}

int main()
{
    int i,n,mx;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        mx = ar[0];
        for(i=1;i<n;i++)
            if(mx<ar[i])
                mx = ar[i];
        for(int exp=1;mx/exp>0;exp*=10)
            Radix_Sort(exp,n);

        for(i=0;i<n;i++)
            printf("%d ",ar[i]);
        printf("\n");
    }
    return 0;
}
