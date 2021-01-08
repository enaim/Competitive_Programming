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

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    string strr[100];
    string str = "CODEFORCES",s;
    int i,j;

    int cnt = 0;
    for(i=0;i<18;i+=2)
    {
        for(j=0;j<=cnt;j++)
        {
            strr[i]+=str[j];
        }
        for(j=cnt+1;j<10;j++)
        {
            strr[i+1]+=str[j];
        }
        cnt++;
    }

    while(cin>>s)
    {
        int n = s.size();
        if(s.find(str)==0)
        {
            puts("YES");
            continue;
        }
        string temp = s, z = str;
        reverse(temp.begin(),temp.end());
        reverse(z.begin(),z.end());
        if(temp.find(z)==0)
        {
            puts("YES");
            continue;
        }
        int flag = 0;
        for(i=0;i<18;i+=2)
        {
            int a = s.find(strr[i]);
            reverse(strr[i+1].begin(),strr[i+1].end());
            int b = temp.find(strr[i+1]);
            if(a==0 && b==0 && s.size()>=10)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            puts("YES");
        else
            puts("NO");

    }

    return 0;
}
