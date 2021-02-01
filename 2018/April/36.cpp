#include<stdio.h>


int main()
{
    int n,mn,mx,i;
    int ar[100];

    printf("Enter number of element in the array : ");
    scanf("%d",&n);

    printf("Enter n elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }

    mn = ar[0];
    mx = ar[0];

    for(i=0;i<n;i++)
    {
        if(mn>ar[i])
        {
            mn = ar[i];
        }
        if(mx<ar[i])
        {
            mx = ar[i];
        }
    }

    printf("Minimum Element is -> %d\n",mn);
    printf("Maximum Element is -> %d\n",mx);

    return 0;
}
