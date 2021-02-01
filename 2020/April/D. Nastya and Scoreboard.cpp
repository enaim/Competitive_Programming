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

char str[2010][10];
char digit[12][8];
int mini[2010];
int maxi[2010];

void initial()
{
    strcpy(digit[0],"1110111");
    strcpy(digit[1],"0010010");
    strcpy(digit[2],"1011101");
    strcpy(digit[3],"1011011");
    strcpy(digit[4],"0111010");
    strcpy(digit[5],"1101011");
    strcpy(digit[6],"1101111");
    strcpy(digit[7],"1010010");
    strcpy(digit[8],"1111111");
    strcpy(digit[9],"1111011");
}

bool isPossible(int k,int t)
{
    int i;
    for(i=0;i<7;i++)
    {
        if(str[k][i]=='1' && digit[t][i]=='0')
            return false;
    }
    return true;
}

int needToMake(int k, int t)
{
    int i,cnt=0;
    for(i=0;i<7;i++)
    {
        if(str[k][i]=='0' && digit[t][i]=='1')
            cnt++;
    }
    return cnt;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    initial();
    int i,j,n,k,mn,mx;
    while(2==scanf("%d%d",&n,&k))
    {
        for(i=0;i<n;i++)
            scanf("%s",str[i]);

        int mnSum = 0,mxSum = 0;
        for(i=0;i<n;i++)
        {
            mn = OO;
            mx = -OO;
            for(j=0;j<10;j++)
            {
                if(isPossible(i,j))
                {
                    int val = needToMake(i,j);
                    mn = min(mn,val);
                    mx = max(mx,val);
                }
            }
            mini[i]=mn;
            maxi[i]=mx;
            mnSum+=mn;
            mxSum+=mx;
        }

        if(k>mxSum || k<mnSum)
        {
            printf("-1\n");
            return 0;
        }

        for(i=0;i<n;i++)
        {
            int ok   = max(k - (mnSum-mini[i]),0);
            int must = min(ok,max(k - (mxSum-maxi[i]),0));

            mnSum-=mini[i];
            mxSum-=maxi[i];

            for(j=9;j>=0;j--)
            {
                if(isPossible(i,j))
                {
                    int val = needToMake(i,j);
                    if(must<=val && val<=ok && val<=k)
                    {
                        strcpy(str[i],digit[j]);
                        k-=val;
                        break;
                    }
                }
            }
            if(j==-1)
            {
                printf("-1\n");
                return 0;
            }
        }
        if(k!=0)
        {
            printf("-1\n");
            return 0;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<10;j++)
            {
                if(strcmp(str[i],digit[j])==0)
                {
                    printf("%d",j);
                    break;
                }
            }
        }
        printf("\n");
    }

    return 0;
}
