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

struct node{
    int left,right,d;
};
node ar[1100];
int cnt,K;

void DEPTH(int k)
{
    ar[ar[k].left].d = ar[k].d+1;
    ar[ar[k].right].d = ar[k].d+1;
    if(ar[k].left!=-1)
        DEPTH(ar[k].left);
    if(ar[k].right!=-1)
        DEPTH(ar[k].right);
}

void SWAP(int k)
{
    if(ar[k].left != -1)
        SWAP(ar[k].left);
    if(ar[k].right != -1)
        SWAP(ar[k].right);
    if(ar[k].d%K==0)
        swap(ar[k].left,ar[k].right);
}

void PRINT(int k)
{
    if(ar[k].left != -1)
        PRINT(ar[k].left);
    if(cnt==0)
        printf("%d",k),cnt++;
    else
        printf(" %d",k);
    if(ar[k].right != -1)
        PRINT(ar[k].right);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,q;
    while(1==scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            node z;
            scanf("%d%d",&z.left,&z.right);
            ar[i]=z;
        }
        ar[1].d = 1;
        DEPTH(1);

        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&K);
            SWAP(1);
            cnt = 0;
            PRINT(1);
            printf("\n");
        }
    }

    return 0;
}
