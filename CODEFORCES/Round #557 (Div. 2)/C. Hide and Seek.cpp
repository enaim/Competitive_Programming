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

vector<int>vec[100010];
int sz[100010];
set<int>st;

int func(int L,int b)
{
    int l,r,mid;
    l = 0;
    r = sz[b]-1;
    if(vec[b][r]<L)
        return -1;
    return 1;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,k,i,x,sum=0,a,b,l;
    while(2==scanf("%d%d",&n,&k))
    {
        for(i=0;i<k;i++)
        {
            scanf("%d",&x);
            st.insert(x);
            vec[x].pb(i);
            sz[x]++;
        }
        sum = n-st.size();
        for(i=1;i<n;i++)
        {
            a = i;
            b = i+1;
            if(sz[a])
            {
                if(sz[b])
                {
                    l = func(vec[a][0],b);
                    if(l==-1)
                        sum++;
                }
                else
                    sum++;
            }
            else
                sum++;
        }

        for(i=n;i>1;i--)
        {
            a = i;
            b = i-1;
            if(sz[a])
            {
                if(sz[b])
                {
                    l = func(vec[a][0],b);
                    if(l==-1)
                        sum++;
                }
                else
                    sum++;
            }
            else
                sum++;
        }

        printf("%d\n",sum);
    }

    return 0;
}
