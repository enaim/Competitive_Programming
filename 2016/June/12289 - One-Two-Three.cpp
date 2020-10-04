#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char w[10];
    int tks,ks=1,len;

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",w);

        len =strlen(w);

        if(len == 5)
            printf("3\n");
        else if((w[0] == 't' && w[1] == 'w') || (w[0] == 't' && w[2] == 'o') || w[1] == 'w' && w[2] == 'o')
            printf("2\n");
        else
            printf("1\n");
    }

    return 0;
}

