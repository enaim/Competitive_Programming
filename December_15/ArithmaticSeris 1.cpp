#include<stdio.h>
#include<math.h>


int main()
{
    int a,d,i,j,n;
    int sum,cur;

    while(3==scanf("%d%d%d",&a,&d,&n))
    {
        for(i=1;i<=n;i++)
        {
            sum =0;
            cur=0;
            for(j=1;j<=i;j++)
            {
                if(j==1)
                    cur=cur+a;
                else cur+=d;
                printf("%d ",cur);

                sum+=cur;
            }
            printf(" sum : %d\n",sum);
        }

    }

    return 0;
}

