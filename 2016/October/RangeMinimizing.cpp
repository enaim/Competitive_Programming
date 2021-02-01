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

    vector<int>vec;
    map<int,int>mp;
    set<int>st;
    int i,a,b,x,n,slow,fast,dif,best,s;

    while(1==scanf("%d",&n))
    {
        st.clear();
        vec.clear();
        for(i=0;i<n;i++)
        {
            cin>>x;
            vec.pb(x);
            st.insert(x);
        }

        slow = 0;
        fast = 0;
        s=1;
        best = OO;

        while(fast != n)
        {
            ++mp[ vec[fast] ];

            if(mp.size() == st.size())
            {
                dif = fast-slow+1;
                if(best > dif)
                {
                    a = slow;
                    b = fast;
                    best = dif;
                }
            }

            while(mp[vec[slow]] > 1)
            {
                mp[vec[slow]]--;
                slow++;
            }

            fst++;
        }
        printf("%d -> %d\n",a,b);
    }

    return 0;
}
