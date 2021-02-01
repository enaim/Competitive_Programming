#include<bits/stdc++.h>
using namespace std;


class User{
    string name,profession;
    int age;
public:
    void setProfile()
    {
        cin>>name>>profession>>age;
    }
    void printProfile()
    {
        cout<<"Name : "<<name<<endl<<"Profession : "<<profession<<endl<<"Age : "<<age;
    }
};

class Question
{
public:
    int Level_1(int p)
    {

    }
    int Level_2(int p)
    {

    }
    int Level_3(int p)
    {

    }
};

class Game{
    int point;
public:
    int Game_Start()
    {
        point = 0;
        point  = Level_1(point);
        if(point >= 8)
        {
            point  = Level_2(point);
        }
        if(point >= 16)
        {
            point  = Level_3(point);
        }
    }
};

class Marking{
    int mark;
public:
    void SetMark(int x)
    {
        mark = x;
    }
    void printMark()
    {
        cout<<"Mark : "<<mark<<endl;
    }
};

int main()
{
    User a;
    a.setProfile();

    return 0;
}
