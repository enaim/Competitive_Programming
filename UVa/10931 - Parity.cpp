#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);ŝ
//    freopen("output.txt","w",stdout);

    int ar[35];
    int i,j,n,cnt;

    while(1==scanf("%d",&n) && n)
    {
        i=0;
        cnt = 0;
        while(n != 0)
        {
            ar[i] = n % 2;
            if(ar[i] == 1)
                cnt++;
            n/=2;
            i++;
        }

        printf("The parity of ");
        for(j=i-1;j>=0;j--)
        {
            printf("%d",ar[j]);
        }
        printf(" is %d (mod 2).\n",cnt);
    }

    return 0;
}


