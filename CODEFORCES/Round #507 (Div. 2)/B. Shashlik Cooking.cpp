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

int flag[1010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,k,i,x,z,ks,last;

    while(2==scanf("%d%d",&n,&k))
    {
        if(n<=k)
        {
            printf("1\n");
            printf("1\n");
            continue;
        }
        if(n<=(k*2)+1)
        {
            printf("1\n");
            printf("%d\n",n-k);
            continue;
        }
        vector<int>vec;
        z = n/((k*2)+1);
        x = n%(((k*2)+1)*z);

        ks = 1;
        if(x<=k && x!=0)
        {
            if(z)
            {
                z--;
                x+=((k*2)+1);
            }
            vec.pb(1);
            while(z--)
            {
                if(ks==1)
                {
                    ks++;
                    vec.pb(1+((2*k)+1));
                    last = 1+((2*k)+1);
                }
                else
                {
                    vec.pb(last+((2*k)+1));
                    last = last+((2*k)+1);
                }
            }
            x = x-(1+k);
            vec.pb(n-(x-k)+1);
        }
        else if(x>k && x!=0)
        {
            while(z--)
            {
                if(ks==1)
                {
                    ks++;
                    vec.pb(k+1);
                    last = k+1;
                }
                else
                {
                    vec.pb(last+((2*k)+1));
                    last = last+((2*k)+1);
                }
            }
            vec.pb(n-(x-k-1));
        }
        else
        {
            while(z--)
            {
                if(ks==1)
                {
                    ks++;
                    vec.pb(k+1);
                    last = k+1;
                }
                else
                {
                    vec.pb(last+((2*k)+1));
                    last = last+((2*k)+1);
                }
            }
        }
        int sz = vec.size();
        cout<<sz<<endl;
        for(i=0;i<sz;i++)
            printf("%d ",vec[i]);
        cout<<endl;
    }

    return 0;
}
