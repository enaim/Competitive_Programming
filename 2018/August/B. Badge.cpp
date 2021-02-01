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

    int i,n,l,ar[10010];
    while(1==scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&ar[i]);
        for(i=1;i<=n;i++)
        {
            map<int,int>mp;
            mp[i]=1;
            l = i;
            while(true)
            {
                mp[ar[l]]++;
                if(mp[ar[l]]==2)
                    break;
                l = ar[l];
            }
            cout<<ar[l]<<" ";
        }
    }

    return 0;
}
