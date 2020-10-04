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

char str[1000010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n;
    while(2==scanf("%d%s",&n,str))
    {
        int open=0,close=0,flag=0,len=0,start;
        for(i=0;i<n;i++)
        {
            if(str[i]==')')
                close++;
            else
                open++;
            if(close>open && flag==0)
            {
                flag = 1;
                start = i;
            }
            if(open==close && flag==1)
            {
                flag = 0;
                len = len + (i-start+1);
            }
            if(open==close && flag==0)
            {
                open = 0;
                close = 0;
            }
        }
        if(open==close)
            printf("%d\n",len);
        else
            printf("-1\n");
    }

    return 0;
}
