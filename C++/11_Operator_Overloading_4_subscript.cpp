#include<iostream>
#include<cassert>
using namespace std;

class String{
public:
    void operator[](string str)
    {
        cout<<str<<endl<<endl;
    }
};

void func()
{
    String S;
    string str = "Naim Elias";
    S[str];
    S["Hello World!"];
}


class Class{
    int ar[10] = {45,58,54,5,4,654,6,54,65,4};
public:
    int* getlist(){ return ar; }
    const int* getlist()const { return ar; }

    int& operator[](int index);
    const int& operator[](int index) const;
};

int& Class :: operator[](int index)
{
    assert(index>=0 && index<10);

    return ar[index];
}

const int& Class :: operator[](int index)const
{
    assert(index>=0 && index<10);

    return ar[index];
}


int main()
{
    func();

    int i;
    const Class cob;

/// below codes doesn't work because of constant
/*
    for(i=0;i<10;i++)
        cob.getlist()[i]=i*10;
    for(i=0;i<10;i++)
        cob[i]=i+1;
*/
    cout<<"constant:-\n\n";

    for(i=0;i<10;i++)
        cout<<cob.getlist()[i]<<" ";
    cout<<endl<<endl;

    for(i=0;i<10;i++)
        cout<<cob[i]<<" ";
    cout<<endl<<endl;


    Class ob;

    cout<<"non-constant:-\n\n";

    for(i=0;i<10;i++)
        ob.getlist()[i]=i*10;

    for(i=0;i<10;i++)
        cout<<ob.getlist()[i]<<" ";
    cout<<endl<<endl;

    for(i=0;i<10;i++)
        ob[i]=i+1;

    for(i=0;i<10;i++)
        cout<<ob[i]<<" ";
    cout<<endl<<endl;


    Class *ob1;
    ob1 = new Class;

    cout<<"Pointer:-\n\n";

    for(i=0;i<10;i++)
        (*ob1)[i]=1000+i;       ///ob1->[i] not working

    for(i=0;i<10;i++)
        cout<<(*ob1).getlist()[i]<<" ";
    cout<<endl<<endl;

//    ob[12]=50;
//    cout<<ob[12]<<endl;

    return 0;
}
