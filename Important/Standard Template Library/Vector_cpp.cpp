#include <stdio.h>
#include <string.h>
#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    vector<int>vec;
    int i,j;

    for(i=0;i<5;i++)
    {
        vec.pb(i);
    }
//    vec.erase(vec.begin()+2);        //like as array deletetion
    printf("Size -> %d\n",vec.size());

/**
    sort(vec.begin(),vec.end());
    sort(vec.rbegin(),vec.rend());     //Reverse Order
*/

    for(i=0;i<5;i++)
    {
        printf("%d - > %d\n",i,vec[i]);
    }
    vec.clear();
    printf("Size -> %d\n",vec.size());
    printf("Is this empty(1) or not(0) -> %d\n",vec.empty());

    vector<int>d[10];
    d[0].pb(2);
    d[0].pb(3);
    d[1].pb(5);
    d[1].pb(6);

    for(i=0;i<2;i++)
    {
        for(j=0;j<d[i].size();j++)
            printf("d[%d] -> %d\n",i,d[i][j]);
    }

    vector<string>vs;
    vs.pb("Naim");
    vs.pb("Hamza");
    for(i=0;i<vs.size();i++)
        cout<<"String -> "<<vs[i]<<endl<<"String length -> "<<vs[i].size()<<endl;

//    sort(vs.begin(),vs.end());
//    sort(vs.rbegin(),vs.rend());
    for(vector<string> :: iterator it = vs.begin(); it != vs.end(); it++)
    {
        string p = *it;
        cout<<p<<endl;
        cout<<*it<<endl;
    }

    return 0;
}
