#include <stdio.h>
#include <string.h>
#include <math.h>


struct Student{
    char name[60];
    int rollNo;
    int classNo;
};

bool comp(Student f, Student s){
/**  See strcmp
    if(strcmp(f.name,s.name))
        return strcmp(f.name,s.name)>0;
*/

    if(f.classNo != s.classNo)
        return f.classNo < s.classNo;

    return f.rollNo<s.rollNo;
}


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

