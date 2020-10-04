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

    int i,j,f,cnt,n,x;
    char str[110];
    while(2==scanf("%d%s",&n,str))
    {
        cnt = f = 0;
        for(i=n-1;i>0;i--)
        {
            if(i%2!=0)
            {
                x = i/2;
                for(j=0;j<=x;j++)
                {
                    if(str[j]==str[j+x+1])
                        continue;
                    else
                        break;
                }
                if(j==x+1)
                {
                    f = 1;
                    break;
                }
            }
        }
        if(f)
            cnt = n - ((i+1)/2) + 1;
        else
            cnt = n;
        printf("%d\n",cnt);
    }

    return 0;
}
