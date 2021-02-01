#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,x,z,n;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        z = 0;
        while(n!=0)
        {
            x = n%10;
            n = n/10;
            if(x == 3 || x == 7)
                z = 1;
        }
        if(z==1)
            printf("Danger\n");
        else
            printf("Welcome\n");
    }

    return 0;
}
