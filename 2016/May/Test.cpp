#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;


int main()
{
    int i,input;
    vector<int> vec;
    cout<<"Vector Size = "<<(int)vec.size()<<endl;

    for(i=0;i<5;i++)
    {
        cin>>input;
        vec.push_back(input);
        cout<<"value of vec ["<< i <<"] = "<<vec[i]<<endl;
    }

    cout<<"Extended Vector Size = "<<(int)vec.size()<<endl;



    return 0;
}

