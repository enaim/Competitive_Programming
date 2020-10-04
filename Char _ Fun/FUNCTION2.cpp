#include <stdio.h>
#include <string.h>
//#include <math.h>


///Return_Type Function_Name(Data_Type1 Paramiter1, Data_Type2 Paramiter2......)




void printArea(int length,int width)
{
    printf("Area of That rectangle: %d\n",length*width);

    if(length!=width)
        return;

    printf("It is also a SQUARE!\n");
}



int main()
{
    printArea(5,10);

    printArea(10,10);

    return 0;
}
