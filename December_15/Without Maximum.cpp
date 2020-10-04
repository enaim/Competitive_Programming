#include<stdio.h>
#include<math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,maximum;
    int a[100],i;



    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

//        for(i=0;i<n;i++)
//            printf("%d : %d\n",i,a[i]);


        maximum = a[0];

        for(i=1;i<n;i++)
        {
            if(maximum<a[i])
                maximum = a[i];
        }

        for(i=0;i<n;i++)
            if(maximum!=a[i])
                printf("%d : %d\n",i,a[i]);

    }

    return 0;
}


