#include<stdio.h>
#include<math.h>


int main()
{
    int a,m,n,sum,i;
    while(1==scanf("%d",&n))
    {
       m=0;
       sum=0;
       for(i=0;i<n;i++)
       {
           scanf("%d",&a);

           if(m<a)
           {
                m=a;

                sum=sum+a;
           }
        }
        printf("sum: %d",sum);
    }

    return 0;
}
