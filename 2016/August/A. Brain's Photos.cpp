#include<stdio.h>


int main()
{
    int n,m,x,i,j;
    char s[10];
    while(scanf("%d%d",&n,&m)==2)
    {
        x=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                scanf("%s",s);
                if(s[0] == 'C' || s[0] == 'M' ||s[0] == 'Y')
                    x=1;
            }
        if(x == 1)
            printf("#Color\n");
        else
            printf("#Black&White\n");
    }

    return 0;
}
