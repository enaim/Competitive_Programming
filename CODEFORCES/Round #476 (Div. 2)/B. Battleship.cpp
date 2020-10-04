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
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

char str[110][110];
int ans,k,n;

int ar[110][110];

void call(int i,int j)
{
    int x = 0;
    for(int l=0;l<k;l++)
    {
        if(str[i][j+l]!='.' || j+l>=n)
            x = 1;
    }

    if(!x)
    {
        for(int l=0;l<k;l++)
            ar[i][j+l]++;
    }
}

void call1(int i,int j)
{
    int x = 0;
    for(int l=0;l<k;l++)
    {
        if(str[i+l][j]!='.' || i+l>=n)
            x = 1;
    }
    if(!x)
    {
        for(int l=0;l<k;l++)
            ar[i+l][j]++;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j;
    while(2==scanf("%d%d",&n,&k))
    {
        for(i=0;i<102;i++)
            for(j=0;j<102;j++)
                ar[i][j]=0;
        ans = 0;
        for(i=0;i<n;i++)
            scanf("%s",str[i]);

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(str[i][j]=='.')
                    call(i,j);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(str[i][j]=='.')
                    call1(i,j);
            }
        }

        int mx = 0;
        int a = 0;
        int b = 0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(ar[i][j]>mx)
                {
                    mx = ar[i][j];
                    a = i;
                    b = j;
                }
            }
        printf("%d %d\n",a+1,b+1);
    }

    return 0;
}
