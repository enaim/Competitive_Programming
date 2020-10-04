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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

    int ar[30];
    char str[10010];
    int tks,ks=1,n,i,j,cnt;
    scanf("%d",&tks);
    while(tks--)
    {
        cnt = 0;
        scanf("%s",str);
        memset(ar,0,sizeof ar);
        n = strlen(str);
        for(i=0;i<n;i++)
            ar[str[i]-'a']++;
        for(i=0;i<26;i++)
            if(ar[i])
                cnt++;
        if(cnt==1)
            printf("-1");
        else
            for(i=0;i<26;i++)
                for(j=0;j<ar[i];j++)
                    printf("%c",i+'a');
        printf("\n");
    }

    return 0;
}
