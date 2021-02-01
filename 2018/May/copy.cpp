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
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[110000];

    int cnt = 0;
    set<string>st;
    for(int i=0;i<110401;i++)
    {
        gets(str);
        string inp = str;
        stringstream ss;
        ss<<inp;
        string tmp;


        while(ss>>tmp)
        {
            cnt++;
            int sz = tmp.size();
            if(tmp[sz-1]==',')
                tmp[sz-1]='\0';
            st.insert(tmp);
        }
    }
    cout<<cnt<<endl;
    for(auto it:st)
        cout<<it<<endl;

    return 0;
}
