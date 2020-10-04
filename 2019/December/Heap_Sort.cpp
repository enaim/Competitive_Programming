#include<bits/stdc++.h>
using namespace std;


void heapify(int ar[],int n,int i)
{
    int largest = i;
    int left = i*2;
    int right = i*2 + 1;

    if(left<n && ar[left]>ar[largest])
        largest = left;

    if(right<n && ar[right]>ar[largest])
        largest = right;

    if(largest!=i)
    {
        swap(ar[i],ar[largest]);
        heapify(ar,n,largest);
    }
}

void HeapSort(int ar[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(ar,n,i);

    for(int i=n-1;i>=0;i--)
    {
        swap(ar[0],ar[i]);
        heapify(ar,i,0);
    }
}

int main()
{
    int ar[100],n;
    while(1==scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&ar[i]);
        HeapSort(ar,n);
        for(int i=0;i<n;i++)
            printf("%d ",ar[i]);
        printf("\n");
    }
}
