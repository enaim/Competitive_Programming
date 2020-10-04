#include<iostream>
using namespace std;

enum Color
{
    COLOR_BLACK, // assigned 0
    COLOR_RED, // assigned 1
    COLOR_BLUE, // assigned 2
    COLOR_GREEN, // assigned 3
    COLOR_WHITE, // assigned 4
    COLOR_CYAN, // assigned 5
    COLOR_YELLOW, // assigned 6
    COLOR_MAGENTA, // assigned 7
    /*COLOR_SIZE*/      ///use of this we can understand the size of color enumerator list
};

enum Animal
{
    ANIMAL_CAT = -3,
    ANIMAL_DOG, // assigned -2
    ANIMAL_PIG, // assigned -1
    ANIMAL_HORSE = 5,
    ANIMAL_GIRAFFE = 5, // shares same value as ANIMAL_HORSE
    ANIMAL_CHICKEN // assigned 6
};

void printColor(Color color)
{
    if (color == COLOR_BLACK)
        cout << "Black";
    else if (color == COLOR_RED)
        cout << "Red";
    else if (color == COLOR_BLUE)
        cout << "Blue";
    else if (color == COLOR_GREEN)
        cout << "Green";
    else if (color == COLOR_WHITE)
        cout << "White";
    else if (color == COLOR_CYAN)
        cout << "Cyan";
    else if (color == COLOR_YELLOW)
        cout << "Yellow";
    else if (color == COLOR_MAGENTA)
        cout << "Magenta";
    else
        cout << "Who knows!";
    cout<<endl;
}

int main()
{
    Color color = COLOR_BLUE;
    cout<<"color - > "<<color<<endl;

    Animal animal = ANIMAL_CAT;
    cout<<"animal - > "<<animal<<endl;

    int v = ANIMAL_CHICKEN;
    cout<<"v - > "<<v<<endl;
    if(ANIMAL_HORSE==ANIMAL_GIRAFFE)
        cout<<"Equal\n";

    int x;
    cin>>x;
    Color clr = static_cast<Color>(x);

    if(x==COLOR_MAGENTA)
        cout<<"COLOR_MAGENTA\n";
    else
        printColor(clr);

    return 0;
}
