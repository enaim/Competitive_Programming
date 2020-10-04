#include<stdio.h>


int main()
{
    int i,j,n;
    int ar[100];
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=1;i<n;i++)
        {
            j = i-1;
            int temp = ar[i];
            while(j>=0 && ar[j]>temp)
                ar[j+1]=ar[j],j--;
            ar[j+1]=temp;
        }
        for(i=0;i<n;i++)
            printf("%d ",ar[i]);
        printf("\n");
    }

    return 0;
}
