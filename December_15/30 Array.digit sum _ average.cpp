#include<stdio.h>
#include<math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,sum;
    int a[10],i;
    double avg;
    double xy[3];



    while(1==scanf("%d",&n))
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            printf("a[i] : %d\n",a[i]);
            sum+=a[i];
        }

        printf("sum -> %d\n",sum);
        avg = sum/(double)n;

        printf("Average : %.3lf\n",avg);

        for(i=0;i<n;i++)
            if(a[i]>avg)
                printf("%d\n",a[i]);
        printf("\n");
    }

    return 0;
}
