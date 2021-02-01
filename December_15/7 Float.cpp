 #include<stdio.h>


int main()
{
    int a,b,c;
    float x;

    a = 20;
    b = 3;

    c = a/b;

    printf("c:%d\n",c);

    float y=b;

    x = a/b;    ///a and b both are integer.

    printf("x:%f\n",x);

    x = a/y;  ///Mind: y is float not int.

    printf("x:%f\n",x);


    return 0;
}
