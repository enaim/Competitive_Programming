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

int cnt,one,zero,i;
int ar[110];
char str[110];

void func1()
{
    if(zero%2==0 && zero>=ar[i])
    {
        cnt++;
        zero-=ar[i];
    }
    else if(one%2==0 && one>=ar[i])
    {
        cnt++;
        one-=ar[i];
    }
    else if(one>=ar[i])
    {
        cnt++;
        one-=ar[i];
    }
    else if(zero>=ar[i])
    {
        cnt++;
        zero-=ar[i];
    }
    else if(one+zero>=ar[i])
    {
        if(one%2==0)
        {
            cnt++;
            ar[i]-=one;
            one = 0;
            zero-=ar[i];
        }
        else if(zero%2==0)
        {
            cnt++;
            ar[i]-=zero;
            zero = 0;
            one-=ar[i];
        }
        else
        {
            if((one-1+zero-1)>=ar[i])
            {
                cnt++;
                ar[i]-=(one-1);
                one = 1;
                zero-=ar[i];
                ar[i]=0;
            }
        }
    }
}

void func2()
{
    if(zero%2!=0 && zero>=ar[i])
    {
        cnt++;
        zero-=ar[i];
    }
    else if(one%2!=0 && one>=ar[i])
    {
        cnt++;
        one-=ar[i];
    }
    else if(one+zero>=ar[i])
    {
        cnt++;
        if(one%2!=0)
        {
            ar[i]-=one;
            one = 0;
            zero-=ar[i];
        }
        else if(zero%2!=0)
        {
            ar[i]-=zero;
            zero = 0;
            one-=ar[i];
        }
        else
        {
            if(ar[i]<=one)
            {
                one-=ar[i];
                ar[i]=0;
            }
            else if(ar[i]<=zero)
            {
                zero-=ar[i];
                ar[i]=0;
            }
            else
            {
                ar[i]-=one;
                one = 0;
                zero-=ar[i];
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,n,j;
    scanf("%d",&tks);
    while(tks--)
    {
        cnt = one = zero = 0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            ar[i] = strlen(str);
            for(j=0;j<ar[i];j++)
            {
                if(str[j]=='0')
                    zero++;
                else
                    one++;
            }
        }
        sort(&ar[0],&ar[n]);
        for(i=0;i<n;i++)
        {
//            printf("one = %d zero = %d ar[i] = %d\n",one,zero,ar[i]);
            if(ar[i]%2==0)
                func1();
            else
                func2();
        }
        printf("%d\n",cnt);
    }

    return 0;
}
