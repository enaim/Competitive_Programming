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


int Trie[50010*32][2],last;

void add(int n)
{
    int i,curr=0,id;
    for(i=31;i>=0;i--)
    {
        id = (n& (1<<i)) != 0;
        if(Trie[curr][id] != -1)
            curr = Trie[curr][id];
        else
        {
            Trie[curr][id]= ++last;
            memset(Trie[last],-1,sizeof Trie[last]);
            curr = last;
        }
    }
}

int get_min(int n)
{
    int i,curr=0,id,res=0;
    for(i=31;i>=0;i--)
    {
        id = (n & (1<<i)) != 0;
        if(Trie[curr][id] != -1)
            curr = Trie[curr][id];
        else
        {
            res |= (1<<i);
            curr = Trie[curr][!id];
        }
    }
    return res;
}

int get_max(int n)
{
    int i,curr=0,id,res=0;
    for(i=31;i>=0;i--)
    {
        id = (n & (1<<i)) != 0;
        if(Trie[curr][!id] != -1)
        {
            res |= (1<<i);
            curr = Trie[curr][!id];
        }
        else
            curr = Trie[curr][id];
    }
    return res;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        last = 0;
        memset(Trie[last],-1,sizeof Trie[last]);
        add(0);
        scanf("%d",&n);
        int mn = 2147483647,mx=-1,pre_xor = 0,x;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            pre_xor ^= x;
            mn = min(mn,get_min(pre_xor));
            mx = max(mx,get_max(pre_xor));
            add(pre_xor);
        }
        printf("Case %d: %d %d\n",ks++,mx,mn);
    }

    return 0;
}
