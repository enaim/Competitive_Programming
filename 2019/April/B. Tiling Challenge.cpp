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

char str[55][55];
int i,j,f,n;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%s",str[i]);
        f = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(str[i][j]=='.')
                {
                    if(i+2<n && j-1>=0 && j+1<n)
                    {
                        if(str[i+1][j]=='.' && str[i+1][j-1]=='.' && str[i+1][j+1]=='.' && str[i+2][j]=='.')
                        {
                            str[i][j]='#';
                            str[i+1][j]='#';
                            str[i+1][j-1]='#' ;
                            str[i+1][j+1]='#' ;
                            str[i+2][j]='#';
                        }
                        else
                        {
                            f = 1;
                            break;
                        }
                    }
                    else
                    {
                        f = 1;
                        break;
                    }
                }
            }
            if(f==1)
                break;
        }
        if(f)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
