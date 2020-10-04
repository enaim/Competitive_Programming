#include<bits/stdc++.h>


int main()
{
    int n,x,sum1,sum2;
    scanf("%d",&n);
    sum1 = sum2 =0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        sum1+=x;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        sum2+=x;
    }

    if(sum1>=sum2)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
