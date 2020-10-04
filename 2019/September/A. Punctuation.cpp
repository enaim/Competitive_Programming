#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

char str[10010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,f,w,p;
    while(gets(str))
    {
        n = strlen(str);
        w = 0;
        for(i=0;i<n;i++)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                if(i!=0)
                {
                    if(w==0)
                        printf(" ");
                }
                w++;
                printf("%c",str[i]);
            }
            else if((str[i]<'a' || str[i]>'z') && str[i]!=' ')
                printf("%c",str[i]),w=0;
            else
                w=0;
        }
        printf("\n");
    }

    return 0;
}
