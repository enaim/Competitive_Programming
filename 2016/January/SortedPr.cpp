#include<stdio.h>
#include<math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int b,n,minimum,ind,j;
    int a[100],i,flag[100],sorted[100];

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        for(i=0;i<n;i++)
            flag[i] = 0;

        for(i=0;i<n;i++)
        {
            ind=-1;
            for(j=0;j<n;j++)
                if(0==flag[j])
                {
                    ind = j;
                    break;
                }

        for(j=0;j<n;j++)
            if(0==flag[j] && a[ind]>a[j])
                ind = j;

        flag[ind] = 1;
        printf("%d\n",a[ind]);
        }
    }

    return 0;
}

