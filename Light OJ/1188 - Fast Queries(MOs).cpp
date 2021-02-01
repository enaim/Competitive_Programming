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
const int SIZE = 100010;

int sq;

struct Query{
    int l,r,id;
};

bool compare(Query a,Query b)
{
    if(a.l/sq < b.l/sq)
        return true;
    if(a.l/sq == b.l/sq)
        return a.r<b.r;
    return false;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ar[SIZE];
    int Qans[SIZE];
    int freq[SIZE];
    int i,n,q,l1,r1,l,r,sz,ans,x,tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(freq,0,sizeof freq);
        printf("Case %d:\n",ks++);
        scanf("%d%d",&n,&q);
        sq = sqrt(n);
        vector<Query>queries;
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);
        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&l,&r);
            Query a;
            a.l = l;    a.r = r;    a.id = i;
            queries.pb(a);
        }
        sort(queries.begin(),queries.end(),compare);
        l = 1,r = 0,ans = 0;
        for(i=0;i<q;i++)
        {
            l1 = queries[i].l;
            r1 = queries[i].r;
            while(l<l1)
            {
                x = ar[l];
                if(freq[x]==1)
                    ans--;
                freq[x]--;
                l++;
            }
            while(l>l1)
            {
                l--;
                x = ar[l];
                if(freq[x]==0)
                    ans++;
                freq[x]++;
            }
            while(r<r1)
            {
                r++;
                x = ar[r];
                if(freq[x]==0)
                    ans++;
                freq[x]++;
            }
            while(r>r1)
            {
                x = ar[r];
                if(freq[x]==1)
                    ans--;
                freq[x]--;
                r--;
            }
            Qans[queries[i].id] = ans;
        }
        for(i=1;i<=q;i++)
            printf("%d\n",Qans[i]);
    }

    return 0;
}
