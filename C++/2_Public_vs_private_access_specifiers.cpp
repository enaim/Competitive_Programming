#include<stdio.h>
#include<iostream>
using namespace std;

class Point{
    int x,y,z;
public:
    void print(){
        printf("x:%d y:%d z:%d\n",x,y,z);
    }
    void setPoint(int a,int b,int c)
    {
        x = a;
        y = b;
        z = c;
    }
    void copyPoint(const Point &p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
    }
    bool isEqual(const Point &c)
    {
        if(x == c.x && y == c.y && z == c.z)
            return true;
        return false;
    }
};

int main()
{
    Point a,b,c;

    a.setPoint(10,20,30);
    b.copyPoint(a);
    c.setPoint(5,2,6);

    a.print();
    b.print();
    c.print();

    if(a.isEqual(b))
        printf("a and b same\n");
    else
        printf("a and b are not same\n");

    if(b.isEqual(c))
        printf("b and c same\n");
    else
        printf("b and c are not same\n");

    return 0;
}
