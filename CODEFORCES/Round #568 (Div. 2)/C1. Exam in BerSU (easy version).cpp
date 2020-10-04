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

int ar[110];
int i,j,n,m,sum,sum1;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&m))
    {
        priority_queue<int>pq;
        vector<int>vec;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        sum = 0;
        for(i=0;i<n;i++)
        {
            sum1 = sum;
            int sz = 0;
            int cnt = 0;
            while(sum+ar[i]>m)
            {
                int t;
                t = pq.top(),pq.pop();
                t = abs(t);
                sum-=t;
                cnt++;

                vec.pb(t);
                sz++;
            }
            for(j=0;j<sz;j++)
                pq.push(vec[j]);
            vec.clear();

            sum = sum1+ar[i];
            pq.push(ar[i]);
            printf("%d ",cnt);
        }
        printf("\n");
    }

    return 0;
}
