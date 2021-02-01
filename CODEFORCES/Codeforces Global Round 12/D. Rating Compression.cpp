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

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

int ar[300010];
int flag[300010];
string str;
set<int>st;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,j,n,first,last;
        sf(n);
        st.clear();
        for(i=0;i<n;i++)
        {
            sf(ar[i]);
            flag[ar[i]]++;
            st.insert(ar[i]);
        }
        first = -1;
        last = n;
        str.clear();
        str="";
        for(i=1;i<=n;i++)
        {
            if(flag[i])
                str+='1';
            else
            {
                str+='0';
                break;
            }
            if(flag[i]!=1)
                break;
            if(ar[first+1]==i)
            {
                first++;
                continue;
            }
            else if(ar[last-1]==i)
            {
                last--;
                continue;
            }
            else
                break;
        }
        for(j=i+1;j<=n;j++)
            str+='0';
        reverse(str.begin(),str.end());
        if(st.size()==n)
            str[0]='1';
        cout<<str<<endl;
        for(i=1;i<=n;i++)
            flag[i]=0;
    }

    return 0;
}
