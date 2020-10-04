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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

struct LR
{
    int l,r;
};

int cnt;
LR ar[1000];
int dp[1000][1000];
int invalid;

int go(int i,int k)
{
    if(cnt == k)
        return -1;

    int &re = dp[i][k];
    
    if(re != invalid)
        return re;
    if(k==0)
        re = 1 + ar[k].r + go(ar[0].r,k+1);
    else
    {
        re = 1 + (ar[k].r - ar[k].l) + abs(ar[k].r - i) + go(ar[k].l,k+1);
        re = min(re, 1 + (ar[k].r - ar[k].l) + abs(ar[k].l - i) + go(ar[k].r,k+1));
    }

    return re;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    memset(&invalid,0x1f,sizeof invalid);

    int i,j,w,h,x,cnt1,move,tks,cursor,flag;
    char str[1000][1000],garvez;

    scanf("%d",&tks);
    while(tks--)
    {
        memset(dp,0x1f,sizeof dp);
        scanf("%d%d",&w,&h);

        scanf("%c",&garvez);
        scanf("%s",str[0]);
        ar[0].l = 0;
        ar[0].r = 0;
        flag = 0;
        for(i=1;i<w;i++)
        {
            x = str[0][i] - '0';
            if(x%2==0)
            {
                ar[0].r = i;
                flag = 1;
            }
        }

        cursor=0;
        cnt = 1;
        cnt1 = 0;
        for(i=1;i<h;i++)
        {
            scanf("%s",str[i]);
            flag = 0;
            for(j=0;j<w;j++)
            {
                x = str[i][j]-'0';
                if(x%2==0)
                {
                    if(flag==0)
                    {
                        ar[cnt].l = j;
                        ar[cnt].r = j;
                        flag = 1;
                    }
                    else
                        ar[cnt].r = j;
                }
            }
            if(flag==1)
            {   
                cnt++;
                cnt1+=cursor;
                cursor = 0;
            }
            else
                cursor++;
        }

        move = go(0,0);
        printf("%d\n",move+cnt1);
    }

    return 0;
}
