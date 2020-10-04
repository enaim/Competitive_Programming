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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,m,sum,prev,j;
    string str;
    while(2==scanf("%d%d",&n,&m))
    {
        cin>>str;
        sort(str.begin(),str.end());
        int ans = 2e8;
        for(int i=0;i<n;i++)
        {
            sum = 0;
            int cnt = 0;
            for(j=i;j<n;j++)
            {
                if(cnt==m)
                    break;
                if(j==i)
                {
                    sum+=str[j]-'a'+1;
                    prev = str[j]-'a'+3;
                    cnt++;
                }
                else if(prev <= str[j]-'a'+1)
                {
                    sum+=str[j]-'a'+1;
                    prev = str[j]-'a'+3;
                    cnt++;
                }
            }
            if(cnt==m)
                ans = min(sum,ans);
        }
        if(ans==2e8)
            printf("-1\n",ans);
        else
            printf("%d\n",ans);
    }

    return 0;
}
