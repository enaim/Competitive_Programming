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

string str1;
string str[100010];
map<string,int>mp1,mp2;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        mp1.clear();
        mp2.clear();
        int i,n;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin>>str[i];
            mp1[str[i]]++;
        }
        for(i=0;i<n;i++)
        {
            cin>>str1;
            mp2[str1]++;
        }
        int flag = 1;
        for(i=0;i<n;i++)
        {
            if(mp1[str[i]]!=mp2[str[i]])
                flag = 0;
        }
        if(flag)
            printf("Croissant\n");
        else
            printf("Troll\n");
    }

    return 0;
}
