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


int main()
{
//    freopen("leapfrog_ch_2.txt","r",stdin);
//    freopen("leapfrog_ch_2output.txt","w",stdout);

    char str[50010];
    int i,len,cnt;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        cnt = 0;
        scanf("%s",str);
        len = strlen(str);
        for(i=1;i<len;i++)
            if(str[i]=='B')
                cnt++;
        if(len==2)
            printf("Case #%d: N\n",ks++);
        else if(len==3 && cnt==1)
            printf("Case #%d: Y\n",ks++);
        else if(len==3 && (cnt==2 || cnt==0))
            printf("Case #%d: N\n",ks++);
        else if(cnt>=2 && cnt<len-1)
            printf("Case #%d: Y\n",ks++);
        else
            printf("Case #%d: N\n",ks++);
    }

    return 0;
}
