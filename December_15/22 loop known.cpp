#include<stdio.h>


int main()
{
    int a;
    int b;
    int m;

    m=1;

    while(m<4)
    {
        scanf("%d%d",&a,&b);

        if(a>b)
            printf(">\n");
        else if(a<b)
            printf("<\n");
        else
            printf("=\n");
            m++;
    }

    return 0;
}

