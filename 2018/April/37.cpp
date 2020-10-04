#include<stdio.h>


int main()
{
    int n,i,cnt,x;
    int ar[100];

    printf("Enter number of element in the array : ");
    scanf("%d",&n);

    printf("Enter n elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }

    printf("Enter required element : ");
    scanf("%d",&x);

    cnt = 0;
    for(i=0;i<n;i++)
    {
        if(ar[i]==x)
            cnt++;
    }

    if(cnt==0)
    {
        printf("required element is not found\n");
    }
    else
    {
        printf("required element is found and it occurs -> %d times\n",cnt);
    }

    return 0;
}
