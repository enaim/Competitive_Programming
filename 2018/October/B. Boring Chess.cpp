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

int dr[]={ 1, 1,-1,-1,-2, 2,-2, 2};
int dc[]={-2, 2,-2, 2, 1, 1,-1,-1};

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int r,c,cnt=0,i;
        scanf("%d%d",&r,&c);

        for(i=0;i<8;i++)
        {
            if(r+dr[i]>=1 && r+dr[i]<=8 && c+dc[i]>=1 && c+dc[i]<=8)
                cnt++;
        }
        printf("Case %d: %d\n",ks++,cnt);
    }

    return 0;
}
