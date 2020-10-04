#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char c;

    while(cin>>c)
    {

        cout<<"isupper: "<<(bool)isupper(c)<<endl;

        if(isupper(c))
            cout<<"tolower: "<<(char)tolower(c)<<endl;

        cout<<"islower: "<<(bool)islower(c)<<endl;
        if(islower(c))
            cout<<"toupper: "<<(char)toupper(c)<<endl;

        cout<<"isalpha: "<<(bool)isalpha(c)<<endl;
        cout<<"isdigit: "<<(bool)isdigit(c)<<endl;
        cout<<"isalnum: "<<(bool)isalnum(c)<<endl;
        cout<<endl<<endl<<endl;


    }
    return 0;
}
