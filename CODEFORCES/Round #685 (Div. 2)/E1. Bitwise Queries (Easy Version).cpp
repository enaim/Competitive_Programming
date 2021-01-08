#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);


int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,x,axb,axc,bxc,sumab,sumbc,sumac,sumabc,anb,anc,bnc;
    sf(n);

    printf("XOR 1 2\n");
    fflush(stdout);
    scanf("%d",&axb);

    printf("AND 1 2\n");
    fflush(stdout);
    scanf("%d",&anb);

    printf("XOR 2 3\n");
    fflush(stdout);
    scanf("%d",&bxc);

    printf("AND 2 3\n");
    fflush(stdout);
    scanf("%d",&bnc);

    printf("AND 1 3\n");
    fflush(stdout);
    scanf("%d",&anc);

    sumab = axb+2*anb;
    sumbc = bxc+2*bnc;
    axc = axb^bxc;
    sumac = axc+2*anc;
    sumabc = (sumab+sumbc+sumac)/2;

    int ar[n+10];
    ar[1] = sumabc - sumbc;
    ar[2] = sumabc - sumac;
    ar[3] = sumabc - sumab;
    for(int i=4;i<=n;i++)
    {
        printf("XOR 1 %d\n",i);
        fflush(stdout);
        scanf("%d",&x);
        ar[i] = ar[1]^x;
    }
    printf("!");
    for(int i=1;i<=n;i++)
        printf(" %d",ar[i]);
    nn;
    fflush(stdout);

    return 0;
}
