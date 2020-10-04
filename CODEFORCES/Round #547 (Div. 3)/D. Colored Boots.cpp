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

struct node{
    int x,y;
};
node ar[150010];
vector<int>v1,v2,v11,v12,vec1[30],vec2[30];
int n,i,j,t,sz,sz1,sz2,k,cnt,t1,t2;
char str1[150010];
char str2[150010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(3==scanf("%d%s%s",&n,str1,str2))
    {
        for(i=0;i<n;i++)
        {
            if(str1[i]=='?')
                v1.pb(i+1);
            else
                vec1[str1[i]-'a'].pb(i+1);
        }
        for(i=0;i<n;i++)
        {
            if(str2[i]=='?')
                v2.pb(i+1);
            else
                vec2[str2[i]-'a'].pb(i+1);
        }

        cnt = 0;
        for(i=0;i<26;i++)
        {
            sz1 = vec1[i].size();
            sz2 = vec2[i].size();
            for(j=0;j<sz1 && j<sz2;j++)
            {
                ar[cnt].x=vec1[i][j];
                ar[cnt].y=vec2[i][j];
                cnt++;
            }
            for(k=j;k<sz1;k++)
                v11.pb(vec1[i][k]);
            for(k=j;k<sz2;k++)
                v12.pb(vec2[i][k]);
        }

        sz1 = v1.size();
        sz2 = v2.size();

        sz = v12.size();
        for(i=0;i<sz1 && i<sz;i++)
        {
            ar[cnt].x=v1[i];
            ar[cnt].y=v12[i];
            cnt++;
        }
        t1 = i;

        sz = v11.size();
        for(i=0;i<sz2 && i<sz;i++)
        {
            ar[cnt].x=v11[i];
            ar[cnt].y=v2[i];
            cnt++;
        }
        t2 = i;

        for(;t1<sz1 && t2<sz2;)
        {
            ar[cnt].x=v1[t1];
            ar[cnt].y=v2[t2];
            t1++;
            t2++;
            cnt++;
        }

        printf("%d\n",cnt);
        for(i=0;i<cnt;i++)
            printf("%d %d\n",ar[i].x,ar[i].y);
    }

    return 0;
}
