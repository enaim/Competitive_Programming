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

int ar[100010];


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,b,c,d,i,j;
    while(4==scanf("%d%d%d%d",&a,&b,&c,&d))
    {
        int t1 = a;
        int t2 = b;
        int t3 = c;
        int t4 = d;
        int n = a+b+c+d;
        int f;
        for(j=3;j>=0;j--)
        {
            if(j==3 && d==0)
                continue;
            if(j==2 && c==0)
                continue;
            if(j==1 && b==0)
                continue;
            if(j==0 && a==0)
                continue;
            f = 1;
            a = t1;
            b = t2;
            c = t3;
            d = t4;
            ar[0]=j;
            if(j==0)
                a--;
            if(j==1)
                b--;
            if(j==2)
                c--;
            if(j==3)
                d--;
            for(i=1;i<n;i++)
            {
                if(ar[i-1]==3)
                {
                    if(c)
                    {
                        ar[i]=2;
                        c--;
                    }
                    else
                    {
                        f = 0;
                        break;
                    }
                }
                if(ar[i-1]==2)
                {
                    if(d)
                    {
                        ar[i]=3;
                        d--;
                    }
                    else if(b)
                    {
                        ar[i]=1;
                        b--;
                    }
                    else
                    {
                        f = 0;
                        break;
                    }
                }
                if(ar[i-1]==1)
                {
                    if(c)
                    {
                        ar[i]=2;
                        c--;
                    }
                    else if(a)
                    {
                        ar[i]=0;
                        a--;
                    }
                    else
                    {
                        f = 0;
                        break;
                    }
                }
                if(ar[i-1]==0)
                {
                    if(b)
                    {
                        ar[i]=1;
                        b--;
                    }
                    else
                    {
                        f = 0;
                        break;
                    }
                }
            }
            if(f)
                break;
        }
        if(f)
        {
            printf("YES\n");
            for(i=0;i<n;i++)
                printf("%d ",ar[i]);
            printf("\n");
        }
        else
            printf("NO\n");
    }

    return 0;
}
