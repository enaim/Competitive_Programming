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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,x;
    double ans;
    while(1==scanf("%d",&n))
    {
        priority_queue<int>pos,neg;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(i==1)
            {
                pos.push(x);
                ans = x;
                printf("%.2lf\n",ans);
                continue;
            }
            if(i==2)
            {
                if(pos.top()<x)
                {
                    neg.push(-x);
                }
                else
                {
                    neg.push(-pos.top());
                    pos.pop();
                    pos.push(x);
                }
                ans = pos.top()+(-neg.top());
                printf("%.2lf\n",ans/2.0);
                continue;
            }
            if(i%2==0)
            {
                if(pos.top()>x)
                {
                    neg.push(-pos.top());
                    pos.pop();
                    pos.push(x);
                }
                else
                    neg.push(-x);
                ans = pos.top()+(-neg.top());
                printf("%.2lf\n",ans/2.0);
            }
            else
            {
                if(x>=-neg.top())
                {
                    pos.push(-neg.top());
                    neg.pop();
                    neg.push(-x);
                }
                else
                {
                    pos.push(x);
                }
                ans = pos.top();
                printf("%.2lf\n",ans);
            }
        }
    }

    return 0;
}
