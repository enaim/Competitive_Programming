#include<stdio.h>


int main()
{
    int a;
    float f,div;

    int s=scanf("%d%f",&a,&f);

    printf("a: %d\tf:%f\n\n",a,f);

    div = a/f;


    printf("Division: %f\n",div);

    return 0;
}
