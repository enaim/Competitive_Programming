#include<stdio.h>
#include<math.h>


int main()
{
    int i,j,n; ///Iterator
    int a,d,sum,cur;
    while(3==scanf("%d%d%d",&a,&d,&n))
    {
        cur = 0;

        sum= 0;

        for(i=1;i<=n;i++)
        {
            if(i==1)
                cur=a;
            else
                cur+=d;

            printf("%d ",cur);
            sum = sum+cur;
        }

        printf(" Sum: %d",sum);

    }


    return 0;
}
