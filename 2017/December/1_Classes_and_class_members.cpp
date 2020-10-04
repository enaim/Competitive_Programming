#include<stdio.h>
#include<iostream>
using namespace std;


//struct Student{
//    int a=4;
//    double b=6.35;
//    void print(){
//        printf("%d %lf\n",a,b);
//    }
//};
//
//struct Student1{
//    int a;
//    double b;
//    void print(){
//        printf("%d %lf\n",a,b);
//    }
//};

class Student{
public:
    int a = 24;
    double b = 9.25;
    void print(){
        cout<<a<<" "<<b<<endl;
    }
};

class Student1{
public:
    int a;
    double b;
    void print(){
        cout<<a<<" "<<b<<endl;
    }
};

int main()
{
    Student a;
    Student1 b{50 , 65.356};
    a.print();
    b.print();

    return 0;
}
