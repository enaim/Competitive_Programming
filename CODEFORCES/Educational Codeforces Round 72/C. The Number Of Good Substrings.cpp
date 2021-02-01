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

char str[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,cnt,cnt1,f,len,n,k;
    scanf("%d",&tks);
    while(tks--)
    {
        int ans = 0;
        scanf("%s",str);
        n = strlen(str);
        cnt = 0;
        for(i=0;i<n;i++)
        {
            if(str[i]=='0')
                cnt++;
            else
            {
                cnt1 = f = 0;
                for(j=0;j<=22;j++)
                {
                    int bin = 0,cnt2=0,len=0;
                    for(k=i+j;k>=i;k--)
                    {
                        len++;
                        if(k>=n)
                        {
                            f = 1;
                            break;
                        }
                        bin = bin + (str[k]-'0')*(1<<cnt2);
                        cnt2++;
                    }
                    if(f)
                        break;
                    if(bin<=len+cnt)
                        ans++;
                    else
                        break;
                }
                cnt = 0;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
