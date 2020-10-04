#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,a,x=0,cnt;
    char v[100];


    while(1==scanf("%d",&n))
    {
        cnt = 0;
        x=n;
        while( 0 != n )
        {
            a=n%10;
            n/=10;
            cnt++;
        }
        n=x;
        while( 0 != n )
        {
            a=n%10;
            n/=10;
            v[cnt-1]=a+48;
            printf("v: %c\n",v[cnt-1]);
            printf("v: %d\n",v[cnt-1]);
            cnt--;
        }
        printf("string : %s\n",v);
    }
    return 0;
}
