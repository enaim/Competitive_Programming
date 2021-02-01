#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n;

    while(1==scanf("%d",&n))
    {
        if(n%2==0 && n!=2)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

