#include<stdio.h>
#include<math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int c,n,temp;
    int a[100],i;

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        for(i=0;i<n;i=i+2)
            if(i+1<n)
            {
                temp = a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }

        for(i=0;i+1<n;i=i+2)
        {
            printf("x -> : %d\n",a[i]);
            printf("Y -> : %d\n",a[i+1]);
        }
            printf("z -> : %d",a[i]);
    }

    return 0;
}

