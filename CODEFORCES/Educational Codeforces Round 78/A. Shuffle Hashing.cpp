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

int flag[30];
int flag1[30];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        string str,has;
        cin>>str>>has;
        int sz = str.size();
        int i,j;
        memset(flag,0,sizeof flag);
        for(i=0;i<sz;i++)
        {
            flag[str[i]-'a']++;
        }

        int sz1 = has.size();

        int f = 0;
        for(i=0;i<sz1;i++)
        {
            memset(flag1,0,sizeof flag1);
            for(j=i;j<sz1 && j<i+sz;j++)
            {
                flag1[has[j]-'a']++;
            }
            for(j=0;j<26;j++)
                if(flag[j]!=flag1[j])
                    break;
            if(j==26)
            {
                f = 1;
                break;
            }
        }
        if(f)
            printf("YES\n");
        else
            printf("NO\n");
    }


    return 0;
}
