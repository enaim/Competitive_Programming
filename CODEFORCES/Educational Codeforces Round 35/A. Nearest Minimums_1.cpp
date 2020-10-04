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
const double eps = 1e9;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,mn,ar[100010],ind,i,ans;
    while(1==scanf("%d",&n))
    {
        mn = OO;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            if(mn>ar[i])
            {
                mn = ar[i];
                ind = i;
            }
        }
        ans = OO;
        for(i=ind+1;i<n;i++)
        {
            if(ar[i]==mn)
            {
                if(ans == OO)
                    ans = i - ind;
                if(ans && i-ind<ans)
                    ans = i - ind;
                ind = i;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
