#include <stdio.h>

int main() {
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int n,i,x,one=0,two=0,zero=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(!x)
                zero++;
            else if(x==1)
                one++;
            else
                two++;
        }
        int k = 1;
        for(i=0;i<zero;i++)
        {
            if(k)
                printf("0");
            else
                printf(" 0");
            k = 0;
        }
        for(i=0;i<one;i++)
        {
            if(k)
                printf("1");
            else
                printf(" 1");
            k = 0;
        }
        for(i=0;i<two;i++)
        {
            if(k)
                printf("2");
            else
                printf(" 2");
            k = 0;
        }
        printf("\n");
    }

	return 0;
}
