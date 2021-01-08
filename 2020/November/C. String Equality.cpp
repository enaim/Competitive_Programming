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

int flag1[30];
int flag2[30];

char str1[1000010];
char str2[1000010];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,k,flag;
        memset(flag1,0,sizeof flag1);
        memset(flag2,0,sizeof flag2);

        sf2(n,k);
        ssf(str1);
        ssf(str2);
        for(i=0;i<n;i++)
        {
            int ch = str1[i]-'a';
            flag1[ch]++;

            ch = str2[i]-'a';
            flag2[ch]++;
        }
        flag = 0;
        for(i=0;i<26;i++)
        {
            if(flag1[i]<flag2[i])
            {
                flag=1;
                break;
            }
            else
            {
                flag1[i]-=flag2[i];
                flag2[i]=0;
                if(flag1[i]%k!=0)
                {
                    flag=1;
                    break;
                }
                flag1[i+1]+=flag1[i];
                flag1[i]=0;
            }
        }
        if(flag1[26]!=0)
            flag = 1;
        for(i=0;i<26;i++)
            if(flag1[i]!=flag2[i])
            {
                flag = 1;
                break;
            }
        if(flag)
            puts("No");
        else
            puts("Yes");
    }

    return 0;
}
