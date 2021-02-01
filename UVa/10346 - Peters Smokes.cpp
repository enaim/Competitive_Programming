#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,k,temp;

    while(2==scanf("%d%d",&n,&k))
    {
        temp=n;
        while(n>=k)
        {
            n=(n-k) + 1;

            temp = temp+1;
        }
        printf("%d\n",temp);
    }

    return 0;
}


