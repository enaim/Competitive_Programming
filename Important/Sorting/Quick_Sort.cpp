#include<bits/stdc++.h>
using namespace std;

int ar[100];

void Quick_Sort(int first,int last)
{
    if(first>=last)
        return;
    int pivot = first;
    int i = first;
    int j = last;
    while(i<j)
    {
        while(ar[i]<=ar[pivot] && i<last)
            i++;
        while(ar[j]>ar[pivot])
            j--;
        if(i<j)
            swap(ar[i],ar[j]);
    }
    swap(ar[pivot],ar[j]);
    Quick_Sort(first,j-1);
    Quick_Sort(j+1,last);
}

int main()
{
    int i,n;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        Quick_Sort(0,n-1);
        for(i=0;i<n;i++)
            printf("%d ",ar[i]);
        printf("\n");
    }
    return 0;
}
