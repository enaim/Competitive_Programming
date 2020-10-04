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

    int l,r,i,n,x;
    while(2==scanf("%d%d",&l,&r))
    {
        int f = 0;
        for(i=l;i<=r;i++)
        {
            n = i;
            int cnt = 0;
            set<int>st;
            while(n!=0)
            {
                x = n%10;
                n = n/10;
                st.insert(x);
                cnt++;
            }
            if(st.size()==cnt)
            {
                f = 1;
                break;
            }
        }
        if(f)
            printf("%d\n",i);
        else
            printf("-1\n");
    }

    return 0;
}
