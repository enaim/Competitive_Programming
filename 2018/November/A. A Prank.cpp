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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n,cnt,cnt1,mx;
    int ar[110];
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }
        cnt=cnt1=0;
        for(i=0;i<n-1;i++)
        {
            if(ar[i]==ar[i+1]-1)
                cnt++;
            else
                break;
        }
        if(ar[0]==1 || (ar[n-1]==1000 && cnt ==n-1 ))
            mx = max(0,cnt);
        else
            mx = max(0,cnt-1);

        for(i=1;i<n-1;i++)
        {
            cnt = 0;
            for(j=i;j<n-1;j++)
            {
                if(ar[j]==ar[j+1]-1)
                    cnt++;
                else
                    break;
            }
            if(j==n-1 && ar[n-1]==1000)
                mx = max(mx,cnt);
            else
                mx = max(mx,cnt-1);
        }
        printf("%d\n",mx);
    }

    return 0;
}
