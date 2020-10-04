#include<stdio.h>

int Maximum(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    int a,b;

    scanf("%d%d",&a,&b);

    int mx = Maximum(a,b);

    printf("%d\n",mx);

    return 0;
}
