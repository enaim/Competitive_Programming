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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

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

    char str[1000000];
    string s;
    int n;
    map<int,int>mp;
    queue<int>Q;

    while(gets(str))
    {
        s = str;
        stringstream ss;
        ss<<s;
        while(ss>>n)
        {
            mp[n]++;
            if(mp[n]==1)
                Q.push(n);
        }
    }
    while(!Q.empty())
    {
        printf("%d %d\n",Q.front(),mp[Q.front()]);
        Q.pop();
    }

    return 0;
}
