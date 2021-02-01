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

int ar[100],i,n,x,y,f,m;
char str[10010];
char str1[10010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ar['a'-'a']=1;
    ar['e'-'a']=1;
    ar['i'-'a']=1;
    ar['o'-'a']=1;
    ar['u'-'a']=1;

    while(2==scanf("%s%s",str,str1))
    {
        f = 1;
        n = strlen(str);
        m = strlen(str1);
        if(n!=m)
        {
            printf("No\n");
            continue;
        }
        for(i=0;i<n;i++)
        {
            x = str1[i]-'a';
            y = str[i]-'a';
            if(ar[x]!=ar[y])
                f = 0;
        }
        if(f)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
