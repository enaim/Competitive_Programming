#include<stdio.h>
#include<math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int a,n,c,i,b,br[111];
    int g,l,e;

    while(2==scanf("%d%d",&n,&a))
    {
        for(i=0;i<n;i++)
            scanf("%d",&br[i]);

        g=0;
        l=0;
        e=0;

        for(i=0;i<n;i++)
        {
            b = br[i];

            if(a>b)
                g++;
            else if(a==b)
                e++;
            else
                l++;
        }

        printf("%d > : %d\n",a,g);
        printf("%d = : %d\n",a,e);
        printf("%d < : %d\n",a,l);

    }

    return 0;
}

