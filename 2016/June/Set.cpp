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
//    st.erase(33); ///May works



    return 0;
}
