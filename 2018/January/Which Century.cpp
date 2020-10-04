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

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int n,ans;
        scanf("%d",&n);

        if(n%100==0)
            ans = n/100;
        else
            ans = n/100 + 1;

        if(ans%10==1 && ans != 11)
            printf("Case #%d: %dst century!\n",ks++,ans);
        else if(ans%10 == 2 && ans != 12)
            printf("Case #%d: %dnd century!\n",ks++,ans);
        else if(ans%10 == 3 && ans != 13)
            printf("Case #%d: %drd century!\n",ks++,ans);
        else
            printf("Case #%d: %dth century!\n",ks++,ans);
    }

    return 0;
}
