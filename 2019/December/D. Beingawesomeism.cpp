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

char str[70][70];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int r,c,i,j;
        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++)
            scanf("%s",str[i]);

        int flag = 0,f = 0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(str[i][j]=='A')
                    flag = 1;
                if(str[i][j]=='P')
                    f = 1;
            }
        }
        if(flag==0)
        {
            printf("MORTAL\n");
            continue;
        }
        if(f==0)
        {
            printf("0\n");
            continue;
        }

        int cnt = 0;
        int f1 = 0;
        for(i=0;i<c;i++)
        {
            if(str[0][i]=='A')
            {
                f1 = 1;
                cnt++;
            }
        }
        if(cnt==c)
        {
            printf("1\n");
            continue;
        }

        cnt = 0;
        for(i=0;i<c;i++)
        {
            if(str[r-1][i]=='A')
            {
                f1 = 1;
                cnt++;
            }
        }
        if(cnt==c)
        {
            printf("1\n");
            continue;
        }

        cnt = 0;
        for(i=0;i<r;i++)
        {
            if(str[i][0]=='A')
            {
                f1 = 1;
                cnt++;
            }
        }
        if(cnt==r)
        {
            printf("1\n");
            continue;
        }

        cnt = 0;
        for(i=0;i<r;i++)
        {
            if(str[i][c-1]=='A')
            {
                f1 = 1;
                cnt++;
            }
        }
        if(cnt==r)
        {
            printf("1\n");
            continue;
        }


        for(i=0;i<r;i++)
        {
            cnt = 0;
            for(j=0;j<c;j++)
            {
                if(str[i][j]=='A')
                    cnt++;
            }
            if(cnt==c)
                break;
        }
        if(i!=r)
        {
            printf("2\n");
            continue;
        }

        for(j=0;j<c;j++)
        {
            cnt = 0;
            for(i=0;i<r;i++)
            {
                if(str[i][j]=='A')
                    cnt++;
            }
            if(cnt==r)
                break;
        }
        if(j!=c)
        {
            printf("2\n");
            continue;
        }


        if(str[0][0]=='A' || str[r-1][0]=='A' || str[0][c-1]=='A' || str[r-1][c-1]=='A')
        {
            printf("2\n");
            continue;
        }
        else if(f1==1)
        {
            printf("3\n");
            continue;
        }
        else
        {
            printf("4\n");
            continue;
        }
    }

    return 0;
}
