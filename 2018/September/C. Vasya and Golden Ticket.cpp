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

    int i,j,r,x,sum,n,ans,cnt;
    char str[110];

    while(1==scanf("%d",&n))
    {
        scanf("%s",str);
        sum = 0;
        for(i=0;i<n;i++)
        {
            sum+=str[i]-'0';
        }
        ans = 0;
        for(i=2;i<=100;i++)
        {
            if(sum%i==0)
                x = sum/i;
            else
                continue;

            j = 0;
            r = 0;
            cnt = 0;
            while(j!=n)
            {
                if(r+str[j]-'0' < x)
                {
                    r += str[j]-'0';
                    j++;
                }
                else if(r+str[j]-'0' == x)
                {
                    cnt++;
                    j++;
                    r = 0;
                }
                else
                    break;
            }
            if(j==n && r==0 && cnt>=2)
            {
                ans = 1;
                break;
            }
        }
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
