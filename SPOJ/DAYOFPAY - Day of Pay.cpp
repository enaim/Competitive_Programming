#include<stdio.h>


int main()
{
    int tks,ks=1;
    int n;

    while(scanf("%d",&n)==1 && n)
    {
        n= n % 6;
        if(n==1)
            printf("Case %d: Anjan\n",ks++);
        else if(n==2)
            printf("Case %d: Sufian\n",ks++);
        else if(n==3)
            printf("Case %d: Alim\n",ks++);
        else if(n==4)
            printf("Case %d: Shipu\n",ks++);
        else if(n==5)
            printf("Case %d: Sohel\n",ks++);
        else
            printf("Case %d: Sumon\n",ks++);
    }

    return 0;
}
