#include<stdio.h>


int main()
{
    int x  = 10,y = 50;

    const int *p1 = &x;     ///You cannot change the value pointed by p1, but you can change the pointer itself
//    *p1 = 20;     /// not working
    x = 20;
    p1 = &y;

    int *const p2 = &x;     /// You cannot change the pointer p2, but can change the value pointed by p2
    *p2 = 20;
//    p2 = &y;    ///not working

    const int *const p3 = &y;   ///You can neither change the value pointed by p3 nor the pointer p3
//    *p3 = 100; ///not working
//    p3 = &x;  ///not working

    return 0;
}
