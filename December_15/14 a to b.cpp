#include<stdio.h>


int main()
{
    int a;
    int b;

    while(2 == scanf("%d%d",&a,&b))
    {
        while(a<=b)
        {
            printf("a -> %d\n",a);
            a=a+1;
        }
    }

  return 0;
}

