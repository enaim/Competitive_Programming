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
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0;
};
node ar[1000010];

int fo(int n)
{
    int x,ans=1;
    while(n!=0)
    {
        x = n%10;
        n/=10;
        if(x!=0)
            ans*=x;
    }
    return ans;
}

int g(int n)
{
    while(n>=10)
        n = fo(n);
    return n;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,ans,x;
    for(i=1;i<=1000000;i++)
    {
        x = g(i);
        ar[i].a = ar[i-1].a;
        ar[i].b = ar[i-1].b;
        ar[i].c = ar[i-1].c;
        ar[i].d = ar[i-1].d;
        ar[i].e = ar[i-1].e;
        ar[i].f = ar[i-1].f;
        ar[i].g = ar[i-1].g;
        ar[i].h = ar[i-1].h;
        ar[i].i = ar[i-1].i;

        if(x==1)
            ar[i].a++;
        if(x==2)
            ar[i].b++;
        if(x==3)
            ar[i].c++;
        if(x==4)
            ar[i].d++;
        if(x==5)
            ar[i].e++;
        if(x==6)
            ar[i].f++;
        if(x==7)
            ar[i].g++;
        if(x==8)
            ar[i].h++;
        if(x==9)
            ar[i].i++;
    }
    int tks,ks=1,l,r,k;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d",&l,&r,&k);
        if(k==1)
            ans = ar[r].a - ar[l-1].a;
        if(k==2)
            ans = ar[r].b - ar[l-1].b;
        if(k==3)
            ans = ar[r].c - ar[l-1].c;
        if(k==4)
            ans = ar[r].d - ar[l-1].d;
        if(k==5)
            ans = ar[r].e - ar[l-1].e;
        if(k==6)
            ans = ar[r].f - ar[l-1].f;
        if(k==7)
            ans = ar[r].g - ar[l-1].g;
        if(k==8)
            ans = ar[r].h - ar[l-1].h;
        if(k==9)
            ans = ar[r].i - ar[l-1].i;
        printf("%d\n",ans);
    }

    return 0;
}
