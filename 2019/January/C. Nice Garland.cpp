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

char c[8][200010];
char str[200010];
int i,n;

struct node{
    int v=0,ind;
};
node ar[10];
bool compare(node a,node b)
{
    return a.v<b.v;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%s",&n,str))
    {
        for(i=0;i<8;i++)
            ar[i].v=0;
        for(i=0;i<n;i++)
        {
            if(i%3==0)
                c[1][i]='R';
            if(i%3==1)
                c[1][i]='G';
            if(i%3==2)
                c[1][i]='B';
        }

        for(i=0;i<n;i++)
        {
            if(i%3==0)
                c[2][i]='R';
            if(i%3==1)
                c[2][i]='B';
            if(i%3==2)
                c[2][i]='G';
        }

        for(i=0;i<n;i++)
        {
            if(i%3==0)
                c[3][i]='B';
            if(i%3==1)
                c[3][i]='R';
            if(i%3==2)
                c[3][i]='G';
        }

        for(i=0;i<n;i++)
        {
            if(i%3==0)
                c[4][i]='B';
            if(i%3==1)
                c[4][i]='G';
            if(i%3==2)
                c[4][i]='R';
        }

        for(i=0;i<n;i++)
        {
            if(i%3==0)
                c[5][i]='G';
            if(i%3==1)
                c[5][i]='R';
            if(i%3==2)
                c[5][i]='B';
        }

        for(i=0;i<n;i++)
        {
            if(i%3==0)
                c[6][i]='G';
            if(i%3==1)
                c[6][i]='B';
            if(i%3==2)
                c[6][i]='R';
        }

        for(i=1;i<=6;i++)
        {
            c[i][n]='\0';
            ar[i].ind=i;
        }

        for(i=0;i<n;i++)
        {
            if(str[i]!=c[1][i])
            {
                ar[1].v++;
            }

            if(str[i]!=c[2][i])
            {
                ar[2].v++;
            }

            if(str[i]!=c[3][i])
            {
                ar[3].v++;
            }

            if(str[i]!=c[4][i])
            {
                ar[4].v++;
            }

            if(str[i]!=c[5][i])
            {
                ar[5].v++;
            }

            if(str[i]!=c[6][i])
            {
                ar[6].v++;
            }
        }

        sort(&ar[1],&ar[7],compare);

        printf("%d\n%s\n",ar[1].v,c[ar[1].ind]);
    }

    return 0;
}
