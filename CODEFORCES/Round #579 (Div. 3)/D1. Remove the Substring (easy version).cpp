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

char str[2010];
char str1[2010];
int l,r,n,m;

bool sub()
{
    int i,j,cnt;
    i = 0;
    j = 0;
    cnt = 0;
    while(i<n && j<m)
    {
        if(i==l)
            i = r+1;
        if(str[i]==str1[j])
            cnt++,j++;
        if(cnt==m)
            return true;
        i++;
    }
    return false;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%s%s",str,str1))
    {
        n = strlen(str);
        m = strlen(str1);
        int  mx = 0;
        for(l=0;l<n;l++)
        {
            for(r=l;r<n;r++)
            {
                if(sub())
                    mx = max(mx,r-l+1);
            }
        }
        printf("%d\n",mx);
    }

    return 0;
}
