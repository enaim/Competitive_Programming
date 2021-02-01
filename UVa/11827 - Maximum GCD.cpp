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

int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    int i,j,n,mx;
    int ar[110];
    string str;
    stringstream ss;
    getline(cin,str);
    while(tks--)
    {
        getline(cin,str);
        ss.clear();
        ss<<str;
        n = 0;
        while(ss>>ar[n])
            n++;
        mx = 0;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
               mx = max(mx,gcd(ar[i],ar[j]));
        printf("%d\n",mx);
    }

    return 0;
}
