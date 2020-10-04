#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int m,n;
    while(2==scanf("%d%d",&m,&n))
    {
        printf("%d\n",(m*n)-1);
    }

    return 0;
}
