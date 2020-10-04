#include<stdio.h>


struct Rectangle{
    int length,width;
};

struct Temp{
    int ar[10];
};

void initialize(Rectangle *r,int l,int w)
{
    r -> length = l;
    r -> width = w;
}

int Area(Rectangle r)
{
    return r.length*r.width;
}

void changeLength(Rectangle &r)
{
    r.length = 100;
}

Rectangle* func()
{
    Rectangle *x;
    Rectangle y;
    y.length = 20;
    y.width = 15;
    x= &y;
    return  x;
}

void Sample(Temp a)
{
    a.ar[3]=100;        /// it doesn't change in the main function
    for(int i=0;i<5;i++)
        printf("%d ",a.ar[i]);
    printf("\n");
}


int main()
{
    Rectangle R;

    initialize(&R,10,5);
    printf("Length - > %d  Width - > %d\n",R.length,R.width);

    printf("Area - > %d\n",Area(R));

    changeLength(R);
    printf("Length - > %d  Width - > %d\n",R.length,R.width);

    Rectangle *p;
    p = func();
    printf("P : Length - > %d  Width - > %d\n\n",p->length,p->width);


    Temp a;
    for(int i=0;i<5;i++)
        a.ar[i]=i;
    Sample(a);
    for(int i=0;i<5;i++)
        printf("%d ",a.ar[i]);
    printf("\n");

    return 0;
}
