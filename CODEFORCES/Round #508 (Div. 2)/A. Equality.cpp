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

    int n,k,i,j,mn;
    char str[100010];
    int ar[29];

    while(2==scanf("%d%d",&n,&k))
    {
        memset(ar,0,sizeof ar);
        scanf("%s",str);
        for(i=0;i<n;i++)
        {
            int ch = str[i]-'A';
            ar[ch+1]++;
        }
        mn = OO;
        for(i=1;i<=26;i++)
        {
            mn = min(mn,ar[i]);
            if(i==k)
                break;
        }
        for(i=1;i<=k;i++)
            if(ar[i]==0)
                break;

        if(i!=k+1)
            printf("0\n");
        else
            printf("%d\n",mn*k);
    }

    return 0;
}
