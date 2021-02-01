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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int w,s,c,k;
    while(4==scanf("%d%d%d%d",&w,&s,&c,&k))
    {
        if(k==0)
        {
            printf("NO\n");
            continue;
        }
        if(w+s+c<=k || s<k || w+c<k)
        {
            printf("YES\n");
            continue;
        }
        if(w+s+c==w || w+s+c==s || w+s+c==c)
        {
            printf("YES\n");
            continue;
        }
        if(w==0)
        {
            if(min(s,c)<k)
            {
                printf("YES\n");
                continue;
            }
            if(min(s,c)<=k && max(s,c)<=2*k)
            {
                printf("YES\n");
                continue;
            }
            else
            {
                printf("NO\n");
                continue;
            }
        }
        else if(c==0)
        {
            if(min(s,w)<k)
            {
                printf("YES\n");
                continue;
            }
            if(min(s,w)<=k && max(s,w)<=2*k)
            {
                printf("YES\n");
                continue;
            }
            else
            {
                printf("NO\n");
                continue;
            }
        }
        else
        {
            if(s>k)
            {
                if(w+c==k && s<=2*k)
                {
                    printf("YES\n");
                    continue;
                }
                else
                {
                    printf("NO\n");
                    continue;
                }
            }
            if(w<=k && s<=k && c<=k)
            {
                printf("YES\n");
                continue;
            }
            if(w+c<=2*k)
            {
                printf("YES\n");
                continue;
            }
            else
            {
                printf("NO\n");
                continue;
            }
        }
    }

    return 0;
}
