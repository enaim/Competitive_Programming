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

int ans[110];
char s[5];
int i,j,n,ind,cnt1,cnt2;
int a,b,c,d,ai,bi,ci,di;

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

void TOGGLE()
{
    for(j=1;j<=n;j++)
        if(ans[j]!=-1)
            ans[j]=!ans[j];
}

void REVERSE()
{
    for(j=1;j<=n/2;j++)
        swap(ans[j],ans[n-j+1]);
}

void func()
{
    memset(ans,-1,sizeof ans);
    cnt1 = cnt2 = 0;
    ind = 1;
    for(i=1;i<=75;i++)
    {
        if(i>5 && i%5==1)
        {
            if(cnt1 && cnt2)
            {
                a = input(ai);
                c = input(ci);
                if(ans[ai]==a && ans[ci]==c)
                    continue;
                else if(ans[ai]==a && ans[ci]==!c)
                    REVERSE();
                else if(ans[ai]==!a && ans[ci]==!c)
                    TOGGLE();
                else
                {
                    TOGGLE();
                    REVERSE();
                }
            }
            else if(cnt1)
            {
                a = input(ai);
                b = input(bi);
                if(ans[ai]==!a && ans[bi]==!b)
                    TOGGLE();
            }
            else
            {
                c = input(ci);
                d = input(di);
                if(ans[ci]==!c && ans[di]==!d)
                    TOGGLE();
            }
        }
        else
        {
            ans[ind]=input(ind);
            ans[n-ind+1]=input(n-ind+1);
            if(ans[ind]==ans[n-ind+1])
            {
                ai = ind;
                bi = n-ind+1;
                cnt1++;
            }
            else
            {
                ci = ind;
                di = n-ind+1;
                cnt2++;
            }
            ind++;
        }
        if(ind-1==(n/2))
            break;
    }
    print();
    return;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d%d",&tks,&n);
    while(tks--)
        func();

    return 0;
}
