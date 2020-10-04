#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

typedef pair<int,int>pii;
typedef pair<int,string>pis;
typedef pair<int,pis>pipis;


vector<pii>v;

int main()
{

    pii a;
    a = make_pair(1,3);
    v.push_back(a);
    v.push_back(make_pair(1,-3));
    v.push_back(make_pair(2,3));
    v.push_back(make_pair(-5,4));

    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;

    puts("----------------");
    for(vector<pii>::iterator it = v.begin();it  != v.end();it++)
    {
        pii p = *it;
        cout<<it->first<<" "<<it->second<<endl;//cout<<p.first<<" "<<p.second<<endl;
    }

    vector<string>vs;

    vs.push_back("ZZZ");
    vs.push_back("Z");
    vs.push_back("BB");
    vs.push_back("AAA");
    vs.push_back("Maksud");
    vs.push_back("Hamza");

    puts("String Ascending:");
    sort(vs.begin(),vs.end());
    for(int i=0;i<vs.size();i++)
        cout<<vs[i]<<endl;

    puts("String Descending:");
    sort(vs.rbegin(),vs.rend());
    for(vector<string>::iterator it = vs.begin();it != vs.end();it++)
        cout<<*it<<endl;

}
