#include<bits/stdc++.h>
using namespace std;


int main()
{
    int i,j,mn,ind,n;
    int ar[100];
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<n;i++)
        {
            mn = ar[i];
            ind = i;
            for(j=i+1;j<n;j++)
            {
                if(ar[j]<mn)
                {
                    ind = j;
                    mn = ar[j];
                }
            }
            swap(ar[i],ar[ind]);
        }
        for(i=0;i<n;i++)
            printf("%d ",ar[i]);
        printf("\n");
    }

    return 0;
}
