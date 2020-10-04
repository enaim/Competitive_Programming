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

int i,j;
vector<int>vec[30];
char s[100010];
char t[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=0;i<26;i++)
            vec[i].clear();
        scanf("%s%s",s,t);
        int n = strlen(s);
        int m = strlen(t);
        for(i=0;i<n;i++)
            vec[s[i]-'a'].pb(i);

        int flag = 0;
        int last = -1;
        int cnt = 1;
        for(i=0;i<m;i++)
        {
            int x = t[i]-'a';

            int l = 0,mid;
            int r = vec[x].size()-1;
            if(r==-1)
            {
                flag = 1;
                break;
            }
            if(vec[x][r]<last)
            {
                last = -1;
                cnt++;
            }
            int val = last;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(vec[x][mid]<val)
                    l = mid+1;
                else
                    r = mid-1;
            }
            last = vec[x][r+1] + 1;
        }
        if(flag)
            printf("-1\n");
        else
            printf("%d\n",cnt);
    }


    return 0;
}
