#include<stdio.h>
#include<math.h>
#include<string.h>


#include<algorithm>
using namespace std;

struct Student
{
    char name[20];
    int marksNo;
    int classNo;
};


Student students[50];


bool compare2(Student a, Student b)
{
    if(a.classNo > b.classNo)
        return true;
    else if(a.classNo == b.classNo && a.marksNo > b.marksNo)
        return true;
    else if(a.classNo ==b.classNo && a.marksNo == b.marksNo && 0 > strcmp(a.name,b.name))
        return true;

    return false;
}


bool compare(Student a, Student b)
{
    if(a.classNo != b.classNo)
        return a.classNo < b.classNo;

    if(a.classNo == b.classNo && a.marksNo > b.marksNo)
        return a.marksNo < b.marksNo;

    return 0 > strcmp(a.name,b.name);

//    else if(a.classNo ==b.classNo && a.marksNo == b.marksNo && 0 != strcmp(a.name,b.name))
//        return 0 < strcmp(a.name,b.name);
//
//    return false;
}







int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n,x;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",students[i].name);
            scanf("%d",&students[i].classNo);
            scanf("%d",&students[i].marksNo);
        }

    sort(&students[0],&students[n],compare);
//        for(i=0;i<n;i++)
//            for(j=0;j<n-i-1;j++)
//                if(compare2(students[j],students[j+1]))
//                {

//                    Student temp=students[j];
//                    students[j]=students[j+1];
//                    students[j+1]=temp;
//                }

        for(i=0;i<n;i++)
        {
            printf("Name  : %s\n",students[i].name);
            printf("Class : %d\n",students[i].classNo);
            printf("Marks  : %d\n\n",students[i].marksNo);
        }
    }

    return 0;
}
