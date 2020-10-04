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

int ar[200010];
int br[200010];
char str1[200010];
char str2[200010];
int i,j,n,m,cnt;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%s%s",&str1,str2))
    {
        n = strlen(str1);
        m = strlen(str2);
        i = 0;
        j = 0;
        cnt = 0;
        while(i<n && j<m)
        {
            if(str1[i]==str2[j])
                ar[j]=i,cnt++,j++;
            if(cnt==m)
                break;
            i++;
        }
        i = n-1;
        j = m-1;
        cnt = 0;
        while(i>=0 && j>=0)
        {
            if(str1[i]==str2[j])
                br[j]=i,cnt++,j--;
             if(cnt==m)
                break;
            i--;
        }
        int mx = 0;
        for(i=0;i<m-1;i++)
            mx = max(mx,br[i+1]-ar[i]-1);
        mx = max(mx,br[0]);
        mx = max(mx,ar[0]);
        mx = max(mx,n-1-br[m-1]);
        mx = max(mx,n-1-ar[m-1]);
        printf("%d\n",mx);
    }

    return 0;
}
