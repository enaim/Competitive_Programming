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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[60][60];
    int r,c,i,j,t;

    while(2==scanf("%d%d",&r,&c))
    {
        for(i=0;i<r;i++)
            scanf("%s",str[i]);
        t = 100;
        while(t--)
        {
            for(i=0;i<r-1;i++)
            {
                for(j=0;j<c;j++)
                {
                    if(str[i][j]=='o' && str[i+1][j]=='.')
                    {
                        str[i][j]='.';
                        str[i+1][j]='o';
                    }
                }
            }
        }
        for(i=0;i<r;i++)
            printf("%s\n",str[i]);
    }

    return 0;
}
