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

int Distance(int x1,int y1,int x2,int y2)
{
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy,x,y,ans;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d%d%d%d",&Ax,&Ay,&Bx,&By,&Cx,&Cy);

        Dx = Ax + (Cx-Bx);
        Dy = Ay + (Cy-By);
        x = Ax*By + Bx*Cy + Cx*Dy + Dx*Ay;
        y = Ay*Bx + By*Cx + Cy*Dx + Dy*Ax;
        ans = 0.5*abs(x-y);

        printf("Case %d: %d %d %d\n",ks++,Dx,Dy,ans);
    }

    return 0;
}
