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

char str[200010];
int i,n,x,f,s,e;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        map<int,int>mp;
        scanf("%s",str);
        for(i=1;i<=9;i++)
            scanf("%d",&x),mp[i]=x;
        f = 1;
        s = e = -1;
        for(i=0;i<n;i++)
        {
            if(f==1 && str[i]-'0'<mp[str[i]-'0'])
                s = i,e=i,f=0;
            else if(f==0)
            {
                if(str[i]-'0'<=mp[str[i]-'0'])
                    e = i;
                else
                    break;
            }
        }
        for(i=0;i<n;i++)
        {
            if(i>=s && i<=e)
                printf("%d",mp[str[i]-'0']);
            else
                printf("%c",str[i]);
        }

        printf("\n");
    }

    return 0;
}
