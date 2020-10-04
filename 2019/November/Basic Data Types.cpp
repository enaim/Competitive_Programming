#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin,str);
    stringstream ss;
    ss << str;
    string st;
    char ch;
    while(ss>>st)
    {
        int sz = st.size(),x;
        int dot = -1;
        for(int i=0;i<sz;i++)
            if(st[i]=='.')
                dot = i;
        if(dot!=-1)
        {
            int dis = sz-1-dot;
            cout<<st;
            if(dis<3)
                x = 3-dis;
            else
                x = 9 - dis;
            for(int i=0;i<x;i++)
                cout<<"0";
            cout<<endl;
        }
        else
            cout<<st<<endl;
    }

    return 0;
}
