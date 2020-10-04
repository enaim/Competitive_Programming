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

char str[1000010];
char ar[1000010];
int i,n,cnt;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%s",str))
    {
        n = strlen(str);
        if(n<3)
        {
            printf("0\n");
            continue;
        }
        cnt = 0;
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                if(str[0]==str[1] && str[0]=='v')
                    ar[cnt++]='w',i++;
                continue;
            }
            else if(i+1<n && str[i-1]=='o' && str[i]=='v' && str[i+1]=='v')
            {
                ar[cnt++]='w',i++;
            }
            else if(str[i]==str[i-1] && str[i]=='v')
                ar[cnt++]='w';
            else
                ar[cnt++]=str[i];
        }
        ar[cnt]='\0';
        n = cnt;
        int w = 0;
        for(i=0;i<n;i++)
        {
            if(ar[i]=='w')
                w++;
        }
        ll ans = 0;
        ll c = 0;
        for(i=0;i<n;i++)
        {
            if(ar[i]=='o')
                ans+=(c*abs(w-c));
            else if(ar[i]=='w')
                c++;
        }
//        printf("%s\n",ar);
        printf("%lld\n",ans);
    }

    return 0;
}
