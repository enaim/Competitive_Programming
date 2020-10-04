#include<stdio.h>


int main()
{
    int v = 10;
    int &r = v;     ///assign in declaration

//    &r = v;     //not working

    printf("v = %d\n",v);
    printf("r = %d\n",r);

    r++;
    printf("\nv = %d\n",v);
    printf("r = %d\n",r);

    v = 15;
    printf("\nv = %d\n",v);
    printf("r = %d\n",r);

    return 0;
}
