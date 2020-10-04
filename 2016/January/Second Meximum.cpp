#include<stdio.h>
#include<math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,b,maximum;
    int a[100],i;



    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        maximum = a[0];
        int ind  = 0;
        for(i=1;i<n;i++)
        {
            if(maximum<a[i])
            {
                maximum = a[i];
                ind = i;
            }
        }

        b = a[0];
        if(ind==0)
            b = a[1];

        for(i=0;i<n;i++)
        {
            if(i!=ind)
            {
                if(b<a[i])
                    b = a[i];
            }
        }

        printf("%d\n",b);
    }

    return 0;
}



