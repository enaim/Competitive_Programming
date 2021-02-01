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
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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
    long long v;
    long long ind;

     node(long long v=0,long long ind =0){
        this->v = v;
        this->ind = ind;
    }

    bool operator < (const node& notMe)const {
        if(v == notMe.v)
            return ind > notMe.ind;
        return v > notMe.v;
    }
};

bool compare(node x,node y)
{
    return x.ind<y.ind;
}

node ar[150010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long n,val,i,cnt;
    while(1==scanf("%lld",&n))
    {
        priority_queue<node>pq;
        for(i=0;i<n;i++)
        {
            cin>>val;
            pq.push(node(val,i));
        }
        cnt = 0;
        node x;
        while(!pq.empty())
        {
            x = pq.top();
            pq.pop();
            if(pq.empty())
                break;
            node y = pq.top();
            if(x.v==y.v)
            {
                pq.pop();
                pq.push(node(x.v*2,y.ind));
            }
            else
            {
                ar[cnt].v = x.v;
                ar[cnt].ind = x.ind;
                cnt++;
            }
        }
        ar[cnt].v = x.v;
        ar[cnt].ind = x.ind;
        cnt++;
        sort(&ar[0],&ar[cnt],compare);
        cout<<cnt<<endl;
        for(i=0;i<cnt;i++)
        {
            if(i==0)
                printf("%lld",ar[i].v);
            else
                printf(" %lld",ar[i].v);
        }
        printf("\n");
    }

    return 0;
}
