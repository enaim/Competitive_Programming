#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int s[100],r,N,i;
    while(1==scanf("%d",&N))
    {
        r = 0;
        if(N < 0)
            break;

        if(N == 0)
            printf("0\n");
        else
        {
            while(N != 0)
            {
                s[r++] = N % 3;
                N/=3;
            }

            for(i=r-1;i>=0;i--)
                printf("%d",s[i]);
            printf("\n");
        }
    }

    return 0;
}

