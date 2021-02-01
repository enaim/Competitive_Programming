#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int c[100],a,i,j,n;
    while(1==scanf("%d",&n))
    {
        printf("Decimal : %d\n",n);
        i=0;
        while(n != 0)
        {
            a=n%2;
            n=n/2;
            c[i]=a;
            i++;
        }
        printf("Binary: ");

        for(j=i-1;j>=0;j--)
            printf("%d",c[j]);
        printf("\n");
    }

    return 0;
}

