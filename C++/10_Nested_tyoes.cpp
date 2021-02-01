#include<iostream>
using namespace std;

class Fruit{
public:
    enum FruitType{
        Apple,
        Mango,
        Orange
    };
private:
    FruitType fruit;
public:
    Fruit(FruitType fruit)
    {
        this -> fruit = fruit;
    }
    FruitType get()
    {
        return fruit;
    }
};

int main()
{
///Fruit :: Apple, Fruit:: FruitType:: Apple both are same

    Fruit FRUIT(Fruit :: Apple);
    if(FRUIT.get()==Fruit:: FruitType:: Apple)
        cout<<"Equal\n";
    else
        cout<<"Not Equal\n";

    return 0;
}
