#include<iostream>
#include<cassert>
#include<initializer_list>
using namespace std;


class Class{
    int length{};
    int *arr{};
public:
    Class(int l):length(l)
    {
        arr = new int[length];
    }
    Class (const initializer_list<int>&List):Class(static_cast<int>(List.size()))
    {
        int cnt = 0;
        for(auto it : List)
            arr[cnt]=it,cnt++;
    }
    int& operator[](int index)
    {
        assert(index>=0 && index<length);
        return arr[index];
    }
    int getlength()
    {
        return length;
    }
};


int main()
{
    Class ar{5,4,3,2,1};
    for(int i=0;i<ar.getlength();i++)
        cout<<ar[i]<<' ';
    cout<<endl;

    return 0;
}
