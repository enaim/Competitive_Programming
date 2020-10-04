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

vector<int>vec,vec1;
int ar[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,x,even=0,odd=0;
        vec.clear();
        vec1.clear();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            ar[i]=x;
            if(x%2==0)
                even++,vec.pb(i);
            else
                odd++,vec1.pb(i);
        }
        if(even)
        {
            cout<<1<<endl;
            cout<<vec[0]<<endl;
        }
        else if(odd>=2)
        {
            cout<<2<<endl;
            cout<<vec1[0]<<" "<<vec1[1]<<endl;
        }
        else
            printf("-1\n");
    }

    return 0;
}
