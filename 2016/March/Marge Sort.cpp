#include <stdio.h>
#include <string.h>
#include <math.h>

int tmp[100];
void marge(int ar[], int l, int r);

void margeSort(int ar[], int l, int r)
{
    int mid ;

    if(l==r)
        return ;
    mid=(l+r)/2;
    margeSort(ar,l,mid);
    margeSort(ar,mid+1,r);
    marge(ar,l,r);
}

void marge(int ar[], int l, int r)
{
    int i,j,k,mid,z;

    mid=(l+r)/2;
    i=l;
    j=mid+1;
    k=l;

    while(i<=mid && j<=r)
    {
        if(ar[i] <= ar[j])
        {
            tmp[k]=ar[i];
            i++;
        }
        else
        {
            tmp[k]=ar[j];
            j++;
        }
        k++;
    }
    while(i<=mid || j<=r)
    {
        if(i<=mid)
        {
            tmp[k]=ar[i];
            i++;
        }
        else
        {
            tmp[k]=ar[j];
            j++;
        }
        k++;
    }
    for(z=l;z<=r;z++)
        ar[z]=tmp[z];
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int ar[100];
    int i,n,l,r;


    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        l=0;
        r=n-1;

        margeSort(ar,l,r);

        for(i=0;i<=r;i++)
            printf("%d ",tmp[i]);
        printf("\n\n");
    }

    return 0;
}
