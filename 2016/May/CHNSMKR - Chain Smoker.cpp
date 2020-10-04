#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,x,y,z;

    while(2==scanf("%d%d",&x,&y) && x && y)
    {
        a=0;
        z=20;

        while((x*z) <= y)
        {
            a=2;
            if(z == 26)
                break;
            z++;
        }
        if(a==2)
            z--;

        while((x*z)<=y)
        {
            a=1;
            x++;
        }

        if(a==1)
            printf("%d %d\n",x-1,y-((x-1)*z));
        else
            printf("Not Possible\n");
    }

    return 0;
}


