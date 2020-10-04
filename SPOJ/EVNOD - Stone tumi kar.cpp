#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,n;
    scanf("%d",&tks);
    while(tks--)
    {
        printf("\n\n");
        scanf("%d",&n);
        if(n%2==0)
            printf("Bob");
        else
            printf("Alice");
    }



    return 0;
}
