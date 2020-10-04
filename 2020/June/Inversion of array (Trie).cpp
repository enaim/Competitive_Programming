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

struct node{
    int cnt;
    node* left = NULL;
    node* right = NULL;
};

ll sum;
void Inversion(node* cur, ll n)
{
    for(ll i=63;i>=0;i--)
    {
        int x = n&(1LL<<i);
        if(x!=0)
        {
            if(cur->left!=NULL)
                sum += cur->left->cnt;
            if(cur->right!=NULL)
                cur = cur->right;
            else
            {
                cur->right = new node();
                cur = cur->right;
            }
            cur->cnt += 1;
        }
        else
        {
            if(cur->left!=NULL)
                cur = cur->left;
            else
            {
                cur->left = new node();
                cur = cur->left;
            }
            cur->cnt += 1;
        }
    }
}

void DELETE(node* cur)
{
    if(cur->left!=NULL)
        DELETE(cur->left);
    if(cur->right!=NULL)
        DELETE(cur->left);
    delete(cur);
}

ll ar[10000010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n;
        sum = 0;
        sf(n);
        for(i=0;i<n;i++)
            sl(ar[i]);
        node* root = new node();
        for(i=n-1;i>=0;i--)
            Inversion(root, ar[i]);
        pl(sum);
    }

    return 0;
}
