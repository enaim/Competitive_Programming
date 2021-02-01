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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,k,cnt,ans;

    while(2==scanf("%d%d",&n,&k))
    {
        cnt=1;
        ans = n;
        while(((ans-k)%10) != 0 && (ans%10) !=0)
        {
            ans+=n;
            cnt++;
        }

        printf("%d\n",cnt);
    }

    return 0;
}
