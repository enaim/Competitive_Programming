#include<stdio.h>


int main()
{
    int a,b,m,n;

    m=1;

    scanf("%d",&n);

    while(m<=n)
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
