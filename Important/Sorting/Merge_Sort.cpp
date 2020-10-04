#include<stdio.h>

int ar[100];

void Merge(int l,int m,int r)
{
    int ans[r-l+5];
    int i = l,j = m+1,k = 0;
    while(i<=m && j<=r)
    {
        if(ar[i]<ar[j])
            ans[k++]=ar[i],i++;
        else
            ans[k++]=ar[j],j++;
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
    int i,n;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        Merge_Sort(0,n-1);
        for(i=0;i<n;i++)
            printf("%d ",ar[i]);
        printf("\n");
    }
    return 0;
}
