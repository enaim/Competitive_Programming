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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

int dr[]={1, 0, 0,-1};
int dc[]={0,-1, 1, 0};

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int str[20][20];
    int i,j,k,r,c,cnt,cnt1,x,y;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        cnt1 = 0;
        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                scanf("%d",&str[i][j]);

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cnt = 0;
                for(k=0;k<4;k++)
                {
                    x = i+dr[k];
                    y = j+dc[k];
                    if(x>=0 && x<r && y>=0 && y<c)
                        cnt++;
                }
                if(cnt>str[i][j])
                {
                    cnt1++;
                }
            }
        }
        if(cnt1==r*c)
            printf("Stable\n");
        else
            printf("Unstable\n");
    }


    return 0;
}
