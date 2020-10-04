#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char name[100];
    int i;

    while(scanf("%s",name)==1)
    {
        for(i=0;name[i]>0;i++)
            printf("%d -> %c\n",name[i],name[i]);
    }

    return 0;
}
