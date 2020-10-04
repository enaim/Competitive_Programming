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
    ll ind,item,price;

    node(ll ind=0,ll item = 0,ll price =0)
    {
        this->ind = ind;
        this->item = item;
        this->price = price;
    }

    bool operator < (const node& notMe)const{
        if(notMe.ind==ind)
            return notMe.ind<price;
        return notMe.price<price;
    }
};
node ar[100010];
priority_queue<node>pq;
ll n,m,sum,cost,t,d,x,i;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%lld%lld",&n,&m))
    {
        sum = 0LL;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&x);
            ar[i].ind = i;
            ar[i].item = x;
            sum+=x;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&x);
            ar[i].price = x;
            pq.push(ar[i]);
        }
        ll cost = 0LL;
        while(m--)
        {
            cost = 0LL;
            scanf("%lld%lld",&t,&d);
            if(sum==0LL)
            {
                printf("0\n");
                continue;
            }
            if(ar[t].item>=d)
            {
                ar[t].item-=d;
                sum-=d;
                cost+=(ar[t].price*d);
                d = 0;
            }
            else
            {
                cost+=(ar[t].price*ar[t].item);
                d-=ar[t].item;
                sum-=ar[t].item;
                ar[t].item=0;
                while(true)
                {
                    if(sum==0LL)
                        break;
                    node top = pq.top();
                    t = top.ind;
                    pq.pop();
                    if(ar[t].item>=d)
                    {
                        ar[t].item-=d;
                        sum-=d;
                        cost+=(ar[t].price*d);
                        d = 0;
                        if(ar[t].item>0)
                            pq.push(ar[t]);
                        break;
                    }
                    else
                    {
                        cost+=(ar[t].price*ar[t].item);
                        d-=ar[t].item;
                        sum-=ar[t].item;
                        ar[t].item=0;
                    }
                }
            }
            if(d!=0)
                printf("0\n");
            else
                printf("%lld\n",cost);
        }
    }

    return 0;
}
