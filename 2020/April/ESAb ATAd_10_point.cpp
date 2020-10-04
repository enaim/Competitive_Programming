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

int ans[60];
char s[60];
int i,j,k,t,ind,flag,n,f,x,temp,cnt1,cnt2;
int a,b,c,d,ai,bi,ci,di,ei,fi;

void check()
{
    if(s[0]=='N')
        exit(0);
    return;
}

int input(int q)
{
    printf("%d\n",q);
    fflush(stdout);
    scanf("%s",s);
    check();
    q = s[0]-'0';
    return q;
}

void print()
{
    for(i=1;i<=n;i++)
        printf("%d",ans[i]);
    printf("\n");
    fflush(stdout);
    scanf("%s",s);
    check();
    return;
}

void func1()
{
    j = 1;
    k = n;
    for(i=1;i<=n;i+=2)
    {
        ans[j]=input(j);
        ans[k]=input(k);
        if(ans[j]==ans[k])
        {
            ai = j;
            bi = k;
            cnt1++;
        }
        else
        {
            ci = j;
            di = k;
            cnt2++;
        }
        j++;
        k--;
    }
    return;
}

void func2()
{
    a = input(ai);
    b = input(bi);
    c = input(ci);
    d = input(di);
    return;
}

void func3()
{
    ind = 1;
    for(i=1;i;i++)
    {
        if(i%5==1)
        {
            a = input(ai);
            b = input(bi);
            if(i!=1)
            {
                 if(!ans[ai]==a && !ans[bi]==b)
                    for(j=1;j<=n;j++)
                        if(ans[j]!=-1)
                            ans[j]=!ans[j];
            }
            ans[ai]=a;
            ans[bi]=b;
        }
        else
        {
            ans[ind]=input(ind);
            ans[n-ind+1]=input(n-ind+1);
            ind++;
        }
        if(ind-1==(n/2))
            break;
    }
    print();
    return;
}

void SWAP()
{
    if(ans[ai]==a && ans[bi]==b && ans[ci]==c && ans[di]==d)            ///No change
        return;
    else if(ans[ai]==!a && ans[bi]==!b && ans[ci]==!c && ans[di]==!d)   ///Toggle
    {
        for(j=1;j<=n;j++)
            if(ans[j]!=-1)
                ans[j]=!ans[j];
    }
    else if(ans[ai]==b && ans[bi]==a && ans[ci]==d && ans[di]==c)         ///Reverse
    {
        for(j=1;j<=n/2;j++)
            swap(ans[j],ans[n-j+1]);
    }
    else
    {
        for(j=1;j<=n;j++)
            if(ans[j]!=-1)
                ans[j]=!ans[j];
        for(j=1;j<=n/2;j++)
            swap(ans[j],ans[n-j+1]);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d%d",&tks,&n);
    while(tks--)
    {
        t = 150;
        cnt1 = cnt2 = 0;
        ai = bi = ci = di = -1;
        func1();
        memset(ans,-1,sizeof ans);

        if(cnt1==n/2)
        {
            func3();
            continue;
        }
        if(cnt2==n/2)
        {
            ai = ci;
            bi = di;
            func3();
            continue;
        }
        flag = 0;
        int kss = 1;
        for(i=n+1;i<=t;i+=10)
        {
            ind = 1;
            func2();
            if(kss==1)
            {
                ans[ai]=a;
                ans[bi]=b;
                ans[ci]=c;
                ans[di]=d;
                kss++;
            }
            SWAP();
            for(j=0;j<3;j++)
            {
                if(ans[ind]!=-1)
                {
                    ind++;
                    j--;
                    continue;
                }
                if(ind>n/2)
                {
                    flag = 1;
                    break;
                }
                ans[ind]=input(ind);
                ans[n-ind+1]=input(n-ind+1);
                ind++;
                if(ind>n/2)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        print();
    }

    return 0;
}
