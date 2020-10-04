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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

    map<int,int>mp;
    stack<int>st;
    priority_queue<int>pq;
    int t,x,n;
    while(1==scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d",&x);
            if(x==1)
            {
                scanf("%d",&n);
                pq.push(n);
                st.push(n);
                mp[n]++;
            }
            if(x==2)
            {
                mp[st.top()]--;
                st.pop();
            }
            if(x==3)
            {
                while(mp[pq.top()]==0)
                    pq.pop();
                printf("%d\n",pq.top());
            }
        }
    }

    return 0;
}

