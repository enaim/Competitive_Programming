#include<iostream>
using namespace std;

enum FruitType{
    Apple,
    Mango,
    Orange
};

class Fruit{
public:
    FruitType fruit;
    Fruit(FruitType fruit)
    {
        this -> fruit = fruit;
    }
};

int main()
{
    Fruit FRUIT(Orange);

    if(FRUIT.fruit == Orange)
        cout<<"Orange\n";
    else
        cout<<"Not Orange\n";

    enum class Flower{
        Rose,
        Water_Lily
    };
    Flower flr = Flower::Water_Lily;
    int x = static_cast<int>(flr);
    cout<<x<<endl;

    return 0;
}
