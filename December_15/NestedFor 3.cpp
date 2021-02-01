#include<stdio.h>
#include<math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int a,n,c,i,b,br[111],j;
    int g,l,e;

//    while(1==scanf("%d",&n))
    {
//        for(i=0;i<n;i++)
//            scanf("%d",&br[i]);
        n=3;
        br[0]=3;
        br[1]=2;
        br[2] = 5;


        for(j=0;j<n;j++)
        {
            a = br[j];
            g=0;
            l=0;
            e=0;
            for(i=0;i<n;i++)
            {
                b = br[i];

                if(a>b)
                    l++;
                else if(a==b)
                    e++;
                else
                    g++;
            }

            printf("%d #\t%d,>\t%d,=\t%d,<\n",a,g,e,l);

        }
    }

    return 0;
}

