#include<stdio.h>
#include<math.h>


int main()
{
    int a,b,c,m,n,sum,i;
    double p,q;
    while(1==scanf("%d",&n))
    {
        m=0;
        b=0;
        c=0;
        sum=0;

        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            b=b+a;
            p=(double)b/n;

            if(m<a)
            {
                m=a;
                sum=sum+a;
                c++;
                q=(double)sum/c;
            }
        }

        printf("c -> %d\n",c);
        printf("sum all  -> %d\n",b);
        printf("average all -> %lf\n",p);
        printf("sum rich number -> %d\n",sum);
        printf("average rich number -> %lf\n",q);

    }

    return 0;
}
