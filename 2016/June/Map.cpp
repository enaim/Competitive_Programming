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
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    map<string,int>mp;
    mp["a"] = 20;   ///O(lg(n))
    mp["b"] = 23;
    mp["c"] = 33;
    mp["a"] = 123;

    deb(mp["c"]);   ///O(lg(n))

    for(map<string,int>::iterator it = mp.begin(); it != mp.end(); it++)
        cout<<it->first <<"  "<<it->second<<endl;

    puts("Typeof-----------");
    //Typeof

    for(__typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++)
        cout<<it->first <<"  "<<it->second<<endl;

    return 0;
}
