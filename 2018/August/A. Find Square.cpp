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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ans1,ans2,cnt,cnt1,i,j,k,r,c,x;
    char str[1000][1000];
    while(2==scanf("%d%d",&r,&c))
    {
        for(i=0;i<r;i++)
            scanf("%s",str[i]);
        cnt = cnt1 = x = 0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(str[i][j]=='B')
                {
                    ans1 = i+1;
                    ans2 = j+1;
                    for(k=i;k<r;k++)
                    {
                        if(str[k][j]=='B')
                            cnt++;
                    }
                    for(k=j;k<c;k++)
                    {
                        if(str[i][k]=='B')
                            cnt1++;
                    }
                    x = 1;
                    break;
                }
            }
            if(x)
                break;
        }
        printf("%d %d\n",ans1+(cnt/2), ans2+(cnt1/2));
    }

    return 0;
}
