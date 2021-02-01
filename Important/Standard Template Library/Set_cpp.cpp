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
struct compare{
    bool operator()(const pii& a,const pii& b)const
    {
        return a.second>b.second;
    }
};

int main()
{
    set<int>st;
    set<int>::iterator it;

    st.insert(2);   ///O(lg(n))
    st.insert(2);   ///O(lg(n))
    st.insert(-1);
    st.insert(33);
    st.insert(-2343);
    st.insert(-2343);
    st.insert(2343);

    deb(st.size());     /// O(1)

    for(it=st.begin();it!=st.end();it++)        ///O(n)
        cout<<*it<<endl;

    if(st.find(2) != st.end())      ///O(lg(n))
        puts("The Element Exists");
    else
        puts("The Element does not Exist");

    it = st.find(33);
    st.erase(it);   ///O(lg(n))
//    st.erase(st.find(33));
//    st.erase(33);
    printf("\n\n");
    vector<pii>vec;

    vec.pb(make_pair(10,4));
    vec.pb(make_pair(11,5));
    vec.pb(make_pair(10,7));
    vec.pb(make_pair(15,8));
    vec.pb(make_pair(20,4));

    set<pii,compare>stt;

    for(auto it : vec)
    {
        stt.insert(it);
        printf("%d %d\n",it.first,it.second);
    }
    printf("\n\n");
    for(auto it : stt)
        printf("%d %d\n",it.first,it.second);

    return 0;
}
