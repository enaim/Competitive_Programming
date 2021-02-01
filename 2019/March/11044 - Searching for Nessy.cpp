#include<stdio.h>


int main()
{
    int tks,r,c;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&r,&c);
        r = r-2;
        c = c-2;
        printf("%d\n",((r+2)/3) * ((c+2)/3));
    }
    return 0;
}
