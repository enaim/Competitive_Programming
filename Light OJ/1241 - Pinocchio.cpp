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

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int n,x,cnt = 0;
        set<int>st;
        set<int>::iterator it;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            st.insert(x);
        }
        x = 2;
        for(it=st.begin();it!=st.end();it++)
        {
            if(*it-x>5)
            {
                cnt+=((*it-x)/5);
                if((*it-x)%5!=0)
                    cnt++;
            }
            else if(*it!=2)
                cnt++;
            x = *it;
        }
        printf("Case %d: %d\n",ks++,cnt);
    }

    return 0;
}
