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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

int ans[]={1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};

int main()
{

//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    int a,x,i;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&a);
        if(a==2)
        {
            printf("3\n");
            continue;
        }
        if(a==3)
        {
            printf("1\n");
            continue;
        }
        for(i=2;i<25;i++)
        {
            if(pow(2,i)<=a && a<=pow(2,i+1)-1)
                break;
        }
        int x = pow(2,i+1)-1;
        if(a==x)
        {
            printf("%d\n",ans[i-1]);
        }
        else
            printf("%d\n",x);
    }

    return 0;
}
