#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,a,x,i,j,k;
    char v[100],w[100];

    while(1==scanf("%d",&n))
    {
        for(i=0;0!=n;i++)
        {
            a=n%10;
            printf("a: %d\n",a);

            n/=10;
            printf("n: %d\n",n);

            v[i]=a+48;
            printf("v%d : %c\n",i,v[i]);
        }

        x=strlen(v);
        v[x]=0;
        printf("v : %s\n",v);
//
//        j=0;
//
//        for(k=x-1;k>=0;k--)
//        {
//            w[j]=v[k];
//            j++;
//        }
//        w[x]=0;
//        printf("string : %s\n",w);
    }
    return 0;
}

