#include<stdio.h>
#include<math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int b,n,maximum,minimum,ind;
    int a[100],i;

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        ind = 0;
        maximum = a[0];

        for(i=1;i<n;i++)
        {
            if(maximum<a[i])
            {
                maximum = a[i];
                ind = i;
            }
        }
        printf("%d : %d\n",ind,maximum);

    }

    return 0;
}


