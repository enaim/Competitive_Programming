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

vector<string>vec;
bool compare(string a,string b)
{
    string c,d;
    c = a+b;
    d = b+a;
    return c>d;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n;
    string str;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        vec.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin>>str;
            vec.pb(str);
        }
        sort(vec.begin(),vec.end(),compare);
        printf("Case %d: ",ks++);
        for(i=0;i<n;i++)
            cout<<vec[i];
        printf("\n");
    }

    return 0;
}
