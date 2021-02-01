#include<stdio.h>


struct Rectangle{
    int length;
    int width;
};

int main()
{
    Rectangle r = {10,5};

    printf("Length = %d\n",r.length);
    printf("width = %d\n",r.width);

    Rectangle *p = &r;

//    *p.length = 20;   //not working

    p -> length = 20;   /// or (*p).length = 20;
    p -> width = 10;   /// or (*p).width = 10;

    printf("\nLength = %d\n",r.length);
    printf("width = %d\n",r.width);

    printf("\nLength = %d\n",p -> length);
    printf("width = %d\n",p -> width);

    return 0;
}
