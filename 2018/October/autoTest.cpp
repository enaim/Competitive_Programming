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
#include <sstream>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

struct Com{

    bool operator()(const int &a, const int &b)
    {
        return a<b;
    }
};


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    vector<int>v = {5,6,2,9};

    auto lmd = [](int a, int b){return a<b;};

    sort(v.begin(),v.end(), lmd);
    ConPnt(v);
    random_shuffle(v.begin(),v.end());
    ConPnt(v);

    set<int,decltype(lmd)>st(lmd);

//    set<int,Com>st;

    for(auto i:v){st.insert(i);}
    ConPnt(st);

    auto fun  = [](int n) -> int
    {
        if(n<2) return 1;
        return n*10;
    };


    deb(fun(10));

    return 0;
}
