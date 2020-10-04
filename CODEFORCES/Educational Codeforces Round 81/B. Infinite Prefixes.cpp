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

char str[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,x;

        scanf("%d%d",&n,&x);
        scanf("%s",str);

        int total = 0;
        for(i=0;i<n;i++)
            if(str[i]=='0')
                total++;
            else
                total--;

        bool flag = false;
        int cnt = 0,ans = 0;
        for(i=0;i<n;i++)
        {
            if(total == 0)
            {
                if(cnt == x)
                    flag = true;
            }
            else if(abs(x-cnt)%abs(total)==0)
                if((x-cnt)/(total)>=0)
                    ans++;

            if(str[i]=='0')
                cnt++;
            else
                cnt--;
        }
        if(flag)
            ans = -1;
        printf("%d\n",ans);
    }

    return 0;
}
