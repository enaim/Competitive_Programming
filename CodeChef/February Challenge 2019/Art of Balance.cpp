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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

vector<int>vec;
char str[1000010];
int flag[30];
int ar[30];

bool compare(int a,int b)
{
    return a>b;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,i,j,x,mv,mn,sz,len,n,cnt,ex;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(flag,0,sizeof flag);

        scanf("%s",str);
        len = strlen(str);

        for(i=0;i<len;i++)
            flag[str[i]-'A']++;

        cnt = 0;
        for(i=0;i<26;i++)
            if(flag[i])
                ar[cnt++]=flag[i];

        n = cnt;
        sort(&ar[0],&ar[n],compare);

        vec.clear();
        for(i=1;i<=len/2;i++)
        {
            if(len%i==0 && len/i<=26)
                vec.pb(i);
        }
        vec.pb(len);

        sz = vec.size();
        mn = OO;
        for(j=0;j<sz;j++)
        {
            x = vec[j];
            ex = 0;
            mv = 0;
            for(i=0;i<n && i<len/x;i++)
            {
                if(ar[i]>=x)
                {
                    mv+=(ar[i]-x);
                    ex+=(ar[i]-x);
                }
                else
                {
                    if(ex)
                    {
                        if(ex>=x-ar[i])
                            ex-=(x-ar[i]);
                        else
                            mv+=((x-ar[i])-ex),ex= 0;
                    }
                    else
                        mv+=(x-ar[i]);
                }
            }
            if(i!=0)
                mn = min(mn,mv);
        }
        printf("%d\n",mn);
    }

    return 0;
}
