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

    int n,k,i,j,pos,val;
    vector<int>vec;
    scanf("%d%d",&n,&k);
    for(i=1;i<=k+1;i++)
    {
        printf("? ");
        for(j=1;j<=k+1;j++)
        {
            if(i!=j)
                printf("%d ",j);
        }
        printf("\n");
        fflush(stdout);

        scanf("%d%d",&pos,&val);
        vec.pb(val);
    }

    int mx = vec[0];
    for(i=1;i<vec.size();i++)
        mx = max(mx,vec[i]);

    int cnt = 0;
    for(i=0;i<vec.size();i++)
        if(mx==vec[i])
            cnt++;

    printf("! %d\n",cnt);
    fflush(stdout);

    return 0;
}
