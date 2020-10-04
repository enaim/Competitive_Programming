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

int ans[1010][5];
char str[1010][1010];
int ar[1010];
int n,m,sum,i,j;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++)
            scanf("%s",str[i]);
        for(i=0;i<m;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int x = str[i][j]-'A';
                ans[j][x]++;
            }
        }
        for(j=0;j<m;j++)
        {
            sort(&ans[j][0],&ans[j][5]);
            sum += (ans[j][4]*ar[j]);
        }
        printf("%d\n",sum);
    }

    return 0;
}
