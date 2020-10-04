#include <stdio.h>
#include <string.h>
//#include <math.h>


///Return_Type Function_Name(Data_Type1 Paramiter1, Data_Type2 Paramiter2......)

void printArea(int a)
{
    printf("In  Fun:%d\n",a);
    a =50;
    printf("-> In  Fun:%d\n",a);
}

void printArea2(int a)
{
    printf("PrintArea Two \n");
}

int main()
{
    int a;
    a = 23;

    printArea(a);
    printArea2(a);

    printf("In Main# a:%d\n",a);

    return 0;
}
