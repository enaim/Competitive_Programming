#include <stdio.h>
#include <string.h>
#include <math.h>


int x;



void fun()
{
    x+=50;
}


char ar[1000000];


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    x = 23;

    fun();
    printf("x: %d\n",x);

    gets(ar);

    printf("%s\n",ar);



//    while(1==scanf("",&))
    {
        printf("\n");
    }

    return 0;
}
