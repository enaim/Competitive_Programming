#include<stdio.h>
#include<math.h>


int main()
{
    int i,j,n;
    int sum,cur;

    while(1==scanf("%d",&n))
    {
        sum =0;
        cur=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                printf("%d ",j);
                cur=j;
            }
                sum = sum + cur;
                printf(" sum : %d\n",sum);
        }

    }

    return 0;
}
