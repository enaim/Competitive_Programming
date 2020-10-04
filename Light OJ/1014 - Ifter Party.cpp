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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    set<int>st;
    set<int> :: iterator it;
    int tks,ks=1,p,l,s,i,t;
    scanf("%d",&tks);
    while(tks--)
    {
        st.clear();
        scanf("%d%d",&p,&l);
        s = sqrt(p-l);
        for(i=1;i<=s;i++)
        {
            if((p-l)%i==0)
            {
                if((p-l)/i>l)
                    st.insert((p-l)/i);
                if(i>l)
                    st.insert(i);
            }
        }
        if(st.size()==0)
        {
            printf("Case %d: impossible\n",ks++);
            continue;
        }
        printf("Case %d:",ks++);
        t = 1;
        for(it = st.begin();it!=st.end();it++,t++)
                printf(" %d",*it);
        printf("\n");
    }

    return 0;
}
