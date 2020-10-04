#include<iostream>
using namespace std;


template<class T>
class Storage{
    T  ar[8];
public:
    void Set(int index,const T& val)
    {
        ar[index] = val;
    }
    const T& get(int index)
    {
        return ar[index];
    }
};

template<>
class Storage<bool>
{
    int k;
public:
    storage(int k = 0)
    {
        this->k = k;
    }
    void Set(int index,bool value)
    {
        int mask = 1<<(index-1);
        if(mask&k)
        {
            if(value == true)
                return;
            k = k& ~mask;
        }
        else
        {
            if(value == false)
                return;
            k = k | mask;
        }
        return;
    }
    bool get(int index)
    {
        int mask = 1<<(index-1);
        return k&mask;
    }
};

int main()
{
    Storage<int>ob;
    for(int i=0;i<8;i++)
        ob.Set(i,i+10);
    for(int i=0;i<8;i++)
        cout<<ob.get(i)<<endl;

    Storage<bool>temp;

    for(int i=0;i<8;i++)
        temp.Set(i,1);
    for(int i=2;i<4;i++)
        temp.Set(i,0);
    for(int i=0;i<8;i++)
        if(temp.get(i))
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;

    return 0;
}
