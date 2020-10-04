///http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1006
#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<utility>
#include<functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>
//#include <assert.h>
//#include<unordered_set>
//#include<unordered_map>



#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define deb(a)      cerr<<"#"<<__LINE__<<" -> "<<#a<<"  "<<a<<endl;
#define popcount(a) (__builtin_popcountll(a))
#define SZ(a)       ((int)a.size())
#define fs           first
#define sc           second
#define pb          push_back
#define ll          long long
#define ld          long double
#define MP          make_pair
#define SS          stringstream
#define VS          vector<string>
#define VI          vector<int>
#define CON(a,b)  ((a).find(b)!=(a).end())
#define mem(a,b)    memset(a,b,sizeof(a))
#define memc(a,b)   memcpy(a,b,sizeof(b))
#define accu(a,b,c) accumulate((a),(b),(c))
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fii(a,b)    for(i=a;i<b;i++)
#define fij(a,b)    for(j=a;j<b;j++)
#define fik(a,b)    for(k=a;k<b;k++)
#define fil(a,b)    for(l=a;l<b;l++)
#define ri(i,a)     for(i=0;i<a;i++)
#define rii(a)      for(i=0;i<a;i++)
#define rij(a)      for(j=0;j<a;j++)
#define rik(a)      for(k=0;k<a;k++)
#define ril(a)      for(l=0;l<a;l++)
#define fore(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define ERR         (1e-7)
#define EQ(a,b)     (fabs((a)-(b))<ERR)
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
#define p2(a)       (1LL<<a)
#define EX(msk,a)   (msk&p2(a))
#define isInRange(v,l,h) (min(l,h)<=v && v<=max(l,h))


#define debug(a...)          {cout<<" #--> ";dbg,a; cout<<endl;}

struct debugger
{
    ///Collected from rudradevbasak
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;


const double pi=acos(-1.0);
const double eps=1e-7;

template<class TT>TT sqr(TT a){return a*a;}

struct P
{
    ll x,y;
    P(){
        x=y=0;
    }

    P(ll x,ll y){
        this->x=x;
        this->y=y;
    }

    bool operator<(const P &b)const{
        if(x!=b.x)  return x<b.x;
        return y<b.y;
    }

    void scan(){cin>>x>>y;}
    void print(){cout<<x<<"  "<<y<<endl;}
};

P pvt;

P mv(P a,P b){return P(b.x-a.x,b.y-a.y);}
ll cp(P a,P b){return a.x*b.y-a.y*b.x;}
ll sdis(P a,P b){return sqr(a.x-b.x)+sqr(a.y-b.y);}

bool comp(P a,P b)
{
    ll c = cp(mv(pvt,a),mv(pvt,b));

    if(c)   return c>0;
    return sdis(pvt,a)<sdis(pvt,b);

}

vector<P> makeConvexHull(vector<P> p)
{
    int nConvex=SZ(p),i,j;

    if(nConvex<4) return p;

/**     IF ALL POINTS ARE CO-LINER   */

//    j=0;
//    for(i=2;i<nConvex;i++)
//        if(cp(mv(p[0],p[1]),mv(p[0],p[i]))==0)
//            j++;
//    if(j+2==nConvex)  return P

    pvt=p[0];
    for(int i=1;i<nConvex;i++)
        if(pvt.y>p[i].y)    pvt=p[i];
        else if(pvt.y==p[i].y && pvt.x>p[i].x)    pvt=p[i];

    sort(all(p),comp);

    j=2;
    for(int i=2;i<nConvex;i++)
    {
        while(j>1 && cp(mv(p[j-2],p[j-1]),mv(p[j-2],p[i]))<0)    j--;
        p[j++]=p[i];
    }
    p.resize(j);
    return p;
}


vector<P>al,an;


double getArea(vector<P>p)
{
    p.pb(p[0]);
    int i,n=SZ(p);

    double ans=0;

    fii(1,n)
        ans+=p[i].x*p[i-1].y-p[i].y*p[i-1].x;

    return fabs(ans/2);
}

int main()
{
    int i,j,k,tks=1,ks=1,n,f,s,mx;
    P in;

    while(cin>>n && n)
    {
        al.clear();

        rii(n)
        {
            in.scan();
            al.pb(in);
        }

        an=makeConvexHull(al);
        double x=getArea(al),y=getArea(an);
        double ans=100*(y-x)/y;
//        deb(ans);
        printf("Tile #%d\nWasted Space = %.2lf %\n\n",ks++,ans);
    }

    return 0;
}




