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

int n,i,cnt,ar[20],temp,x,mx,ans,j;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        temp = n;
        ans = 1;
        cnt = 0;
        while(temp!=0)
        {
            ar[cnt]=temp%10;
            ans*=ar[cnt];
            temp/=10;
            cnt++;
        }
        for(i=0;i<cnt/2;i++)
            swap(ar[i],ar[cnt-i-1]);

        mx = ans;
        if(n>=10)
        for(i=0;i<cnt;i++)
        {
            ans = 1;
            for(j=0;j<=i-1;j++)
                ans*=ar[j];
            ans*=(ar[i]-1);
            ans = max(ans,1);
            for(j=i+1;j<cnt;j++)
                ans*=9;
            mx = max(ans,mx);
        }
        printf("%d\n",mx);
    }

    return 0;
}
