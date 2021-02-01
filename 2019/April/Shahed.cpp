#include<iostream>
using namespace std;

class Drive38{
    int Total_Capacity,Used;
public:
    Drive38()
    {
        Used=0;
        Total_Capacity = 10;
    }
    void Upload(int Size)
    {
        if(Used + Size > Total_Capacity)
            cout<<"Insufficient Storage"<<endl;
        else
            Used = Used + Size;
    }
    void Upgrade(int Size)
    {
        Total_Capacity = Total_Capacity + Size;
    }
    void View()
    {
        cout<<"TotalCapacity = "<<Total_Capacity<<endl;
        cout<<"Used = "<<Used<<endl;
    }
};

int main()
{
    Drive38 obj;
    obj.View();
    obj.Upload(4);
    obj.View();
    obj.Upgrade(3);
    obj.View();


    return 0;
}
