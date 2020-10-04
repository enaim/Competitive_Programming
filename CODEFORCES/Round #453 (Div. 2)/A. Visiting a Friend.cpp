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

    int ar[110],n,x,y,m,i,j,mx,z;
    while(2==scanf("%d%d",&n,&m))
    {
        z = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            if(i==0)
            {
                if(x!=0)
                {
                    z = 1;
                }
                mx = y;
            }
            else if(mx<x && mx<m)
                z = 1;
            else if(mx<y)
                mx = y;

        }
        if(z || mx<m)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
