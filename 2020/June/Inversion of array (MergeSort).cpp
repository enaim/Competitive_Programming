#include<stdio.h>

long long  ar[10000010];
long long sum;

void Merge(int l,int m,int r)
{
    long long ans[r-l+5];
    int i = l,j = m+1,k = 0;
    while(i<=m && j<=r)
    {
        if(ar[i]<=ar[j])
            ans[k++]=ar[i],i++;
        else
        {
            ans[k++]=ar[j],j++;
            sum += (m-i+1);
        }
    }
    while(i<=m) ans[k++]=ar[i],i++;
    while(j<=r) ans[k++]=ar[j],j++;
    k = 0;
    for(i=l;i<=r;i++)
        ar[i] = ans[k],k++;
}

void Merge_Sort(int l,int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        Merge_Sort(l,m);
        Merge_Sort(m+1,r);
        Merge(l,m,r);
    }
}

int main()
{
    int i,n,tks;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        sum = 0LL;
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i]);
        Merge_Sort(0,n-1);
        printf("%lld\n",sum);
    }

    return 0;
}
