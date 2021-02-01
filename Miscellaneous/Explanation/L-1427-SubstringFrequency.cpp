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
#include <assert.h>


#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define deb(a)      cerr<<" -> "<<#a<<"  "<<a<<endl;
#define oo          (1<<30)
#define ERR         1e-5
#define PRE         1e-8
#define popcount(a) (__builtin_popcount(a))
#define SZ(a)       ((int)a.size())
#define X           first
#define Y           second
#define PB          push_back
#define LL          long long
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
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
//#define sqr(a)      ((a)*(a))
#define p2(a)       (1LL<<a)
#define EX(msk,a)   (msk&p2(a))
#define INC(a,b,c)   (b<=a&&a<=c)


//#define debug(args...)          {dbg,args; cerr<<endl;}
//#define debug(args...)          {cout<<" #--> ";dbg,args; cerr<<endl;}
#define debug(a...)          {cerr<<" #--> ";dbg,a; cerr<<endl;}

struct debugger
{
    ///Collected from rudradevbasak
    template<typename T> debugger& operator , (const T v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;




//const double pi=2*acos(0.);
const double pi=acos(-1.0);

const double eps=1e-7;

template<class TT>TT sqr(TT a){return a*a;}

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}

//typedef pair<int,int> pii;

//typedef double type;
//struct P{
//    type x,y,z;
//    P(type xi=0,type yi=0,type zi=0):x(xi),y(yi),z(zi){};
//    void scan(){cin>>x>>y>>z;}
//    void scan1(){scanf("%lf%lf%lf",&x,&y,&z);}
//};


//bool operator < (const P &a,const P &b){return a>b;}
//bool com(P a,P b){return;}

//struct pq{int n,w;
//    pq(int nn=0,int ww=0):n(nn),w(ww){}
//    bool operator<(const pq &b) const{return w<b.w;}
//};


struct nod
{
    int l,d,sf,chi[26],f;

    void Clear()
    {
        l=d=sf=f=0;
        memset(chi,0,sizeof chi);
    }
};

nod T[250010];
char ptr[501][502],txt[1000010];
int end[501],num;

queue<int>Q;

void build(int n)
{
    int i,j,c,l,cur,u,v,p;
    num=0;

    T[0].Clear();

    for(i=0;i<n;i++)
    {
        cur = 0;
        l = strlen(ptr[i]);
        for(j=0;j<l;j++)
        {
            c = ptr[i][j]-'a';
            if(T[cur].chi[c])
                cur = T[cur].chi[c];
            else
            {
                T[cur].chi[c] = ++num;
                T[num].Clear();
                T[num].d=T[cur].d+1;
                cur = num;
            }
        }
        end[i] = cur;
    }


    for(i=0;i<26;i++)
    {
        if(T[0].chi[i])
        {
            cur = T[0].chi[i];
            Q.push(cur);
            T[i].l=0;
        }
    }

    while(!Q.empty())
    {
        u = Q.front();Q.pop();

        for(i=0;i<26;i++)
        {
            if(T[u].chi[i])
            {
                v = T[u].chi[i];
                p = T[u].l;

                while(p && !T[p].chi[i])
                    p = T[p].l;
                T[v].l = T[p].chi[i];
                Q.push(v);
            }
            else T[u].chi[i] = T[T[u].l  ].chi[i];
        }
    }
}

pair<int,int> a[250010];

void search()
{
    int l,i,c,ch;
    l = strlen(txt);

    c = 0;
    for(i=0;i<l;i++)
    {
        ch = txt[i] - 'a';
        c = T[c].chi[ch];
        T[c].sf++;
    }

    for(i=0;i<=num;i++)
    {
        a[i].Y = i;
        a[i].X=T[i].d;
    }
    sort(a,a+num+1);

    for(i=num;i>-1;i--)
    {
        T[T[a[i].Y].l].sf+=T[a[i].Y].sf;
    }
}




int main()
{
    //freopen("in.in","r",stdin);

    int i,j,k,tks,ks=1,n,m,sum;

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%s",&n,txt);

        rii(n)
        {
            scanf("%s",ptr[i]);
        }
        build(n);
        search();

        printf("Case %d:\n",ks++);

        for(i=0;i<n;i++)
            printf("%d\n",T[end[i]].sf);
    }

    return 0;
}


