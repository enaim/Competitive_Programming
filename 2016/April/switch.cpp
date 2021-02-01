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
        switch(n)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 9:
                printf("ODD\n");
                break;


            case 2:
            case 4:
            case 6:
            case 8:
            case 10:
                printf("Even\n");
                break;

            default :
                printf("Invalid number\n");
                break;
        }
    }

    return 0;
}

