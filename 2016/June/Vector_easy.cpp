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
#define pb push_back

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

//    sort(vec.begin(),vec.end());
    sort(vec.rbegin(),vec.rend());

    for(i=0;i<5;i++)
        cout<<"value of vec ["<< i <<"] = "<<vec[i]<<endl;

    vector<int> g[10];
    g[0].push_back(15);
    g[0].push_back(23);
    g[3].pb(23);
    g[4].pb(23);
//    g[0].clear();

    for(i=0;i<g[0].size();i++)
        cout<<"value of g ["<< i <<"] = "<<g[0][i]<<endl;


    vector<string> vs;
    vs.pb("Mohammad");
    vs.pb("Elias");
    vs.pb("Hassan");
    vs.pb("Naim");

    for(int i=0;i<vs.size();i++)
        cout<<vs[i].size()<<endl;

    return 0;
}

