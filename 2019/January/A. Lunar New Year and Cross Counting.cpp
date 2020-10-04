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


int cnt,i,j,n;
char str[1000][1000];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        cnt = 0;
        for(i=0;i<n;i++)
            scanf("%s",str[i]);
        for(i=1;i<n-1;i++)
        {
             for(j=1;j<n-1;j++)
             {
                 if(str[i][j]=='X' && str[i-1][j-1]=='X'&& str[i-1][j+1]=='X'&& str[i+1][j-1]=='X'&& str[i+1][j+1]=='X')
                    cnt++;
             }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
