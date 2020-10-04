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

char str[500010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,s,e,n,ss,ee,cnt,f;
    while(1==scanf("%s",str))
    {
        n = strlen(str);
        s = e = ss = ee = -1;
        for(i=0;i<n;i++)
        {
            if(str[i]=='[')
            {
                s = i;
                break;
            }
        }
        for(i=n-1;i>-1;i--)
        {
            if(str[i]==']' && s<i)
            {
                e = i;
                break;
            }
        }
        for(i=0;i<n;i++)
        {
            if(str[i]==':' && s<i && i<e)
            {
                ss = i;
                break;
            }
        }
        for(i=n-1;i>-1;i--)
        {
            if(str[i]==':' && i<e && s<i && ss<i)
            {
                ee = i;
                break;
            }
        }
        f = cnt = 0;
        if(s!=-1 && e!=-1 && ss != -1 && ee !=-1 && s<e)
        {
            f = 1;
            for(i=ss;i<=ee;i++)
                if(str[i]=='|')
                    cnt++;
        }
        if(f)
            printf("%d\n",4+cnt);
        else
            printf("-1\n");
    }

    return 0;
}
