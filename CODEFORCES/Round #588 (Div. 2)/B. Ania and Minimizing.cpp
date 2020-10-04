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

char str[200010];
int i,n,k;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&k))
    {
        scanf("%s",str);
        int cnt = 0;
        for(i=0;i<n;i++)
            if(str[i]=='0')
                cnt++;
        if(n==1 && k!=0)
        {
            printf("0\n");
            continue;
        }
        if(k==0 || cnt==n || (str[0]=='1' && cnt==n-1))
        {
            printf("%s\n",str);
            continue;
        }
        cnt = 0;
        for(i=0;i<n;i++)
        {
            if(str[i]=='1' && i==0)
                continue;
            else if(i==0)
                str[i]='1',cnt++;
            else if(str[i]=='0')
                continue;
            else
                str[i]='0',cnt++;
            if(cnt==k)
                break;
        }
        printf("%s\n",str);
    }

    return 0;
}
