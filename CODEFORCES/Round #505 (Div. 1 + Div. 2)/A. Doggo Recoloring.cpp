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

    int ar[30],ans,x,i,n;
    char str[100010];
    while(2==scanf("%d%s",&n,str))
    {
        if(n==1)
        {
            printf("Yes\n");
            continue;
        }
        memset(ar,0,sizeof ar);
        for(i=0;i<n;i++)
        {
            x = str[i]-'a';
            ar[x]++;
        }
        ans = 0;
        for(i=0;i<26;i++)
        {
            if(ar[i]>1)
                ans =1;
        }
        if(ans)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
