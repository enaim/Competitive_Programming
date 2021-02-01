#include <stdio.h>
#include <string.h>
#include <math.h>


struct Student{
    char name[60];
    int rollNo;
    int classNo;
};


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    Student one,two;

    strcpy(one.name,"Hamza");
    one.rollNo = 106;
    one.classNo = 9;

    two = one;

    printf("Name: %s\nClass: %d\nRoll: %d\n",two.name,two.classNo,two.rollNo);

    return 0;
}
