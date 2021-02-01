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

    int v1,v2,v3,v4;
    while(4==scanf("%d%d%d%d",&v1,&v2,&v3,&v4))
    {
        if(v4<=v3 && v4*2>=v3)
        {
            printf("%d\n",v1*2);
            printf("%d\n",v2*2);
            printf("%d\n",v3);
        }
        else if(v3*2>=v4 && v4>v3 && v4<v2)
        {
            printf("%d\n",v1*2);
            printf("%d\n",v2*2);
            printf("%d\n",v4);
        }
        else
            printf("-1\n");
    }

    return 0;
}
