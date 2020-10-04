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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

vector<int>adj[10];

int mx,n,val,i,j,depth;

void go(int val,int depth)
{
    if(val==pow(2,n-1))
    {
        if(depth < mx)
            mx = depth;
        return ;
    }

    for(i=0;i<n;i++)
    {
        if( (val & (1<<i)) > 0)
        {
            for(j=0;j<adj[i].size();j++)
            {
                val = val | 1<<i-1;
                go(val,depth+1);
            }
        }
    }


}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int e,u,v,l,a;

    while(3==scanf("%d%d%d",&n,&e,&l))
    {
        mx = OO;
        val = 0;
        for(i=0;i<e;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].pb(v);
        }
        for(i=0;i<l;i++)
        {
            scanf("%d",&a);
            val |= (1<<a-1);
        }

        go(val,0);

        printf("%d\n",depth);
    }

    return 0;
}
