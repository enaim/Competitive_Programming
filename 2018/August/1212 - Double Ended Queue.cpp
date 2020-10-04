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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,n,m,x,sz;
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        scanf("%d%d",&n,&m);
        deque<int>dq;
        string str;
        sz = 0;
        while(m--)
        {
            cin>>str;
            if(str=="pushLeft")
            {
                scanf("%d",&x);
                if(sz<n)
                {
                    dq.push_back(x);
                    printf("Pushed in left: %d\n",x);
                    sz++;
                }
                else
                    printf("The queue is full\n");
            }
            if(str=="pushRight")
            {
                scanf("%d",&x);
                if(sz<n)
                {
                    dq.push_front(x);
                    printf("Pushed in right: %d\n",x);
                    sz++;
                }
                else
                    printf("The queue is full\n");
            }
            if(str=="popLeft")
            {
                if(sz>0)
                {
                    x = dq.back();
                    dq.pop_back();
                    printf("Popped from left: %d\n",x);
                    sz--;
                }
                else
                    printf("The queue is empty\n");
            }
            if(str=="popRight")
            {
                if(sz>0)
                {
                    x = dq.front();
                    dq.pop_front();
                    printf("Popped from right: %d\n",x);
                    sz--;
                }
                else
                    printf("The queue is empty\n");
            }
        }
    }

    return 0;
}
