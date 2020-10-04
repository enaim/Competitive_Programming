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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)
#define sqr(a)  (a*a)

typedef long long ll;
typedef pair<int,int>pii;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i,x,y;
    vector<int>vec;
    map<int,int>mp;
    while(1==scanf("%d",&n))
    {
        mp.clear();
        vec.clear();
        ll sum1;
        sum1 = 0;
        for(i=1;i<=n;i++)
        {
            mp[i]=1;
            sum1+=i;
        }
        ll sum = sum1/2;
        ll temp = 0;
        ll x = sum;
        int ks=1;
        while(temp!=sum)
        {
            if(mp[x]==1)
            {
                temp+=x;
                vec.pb(x);
                break;
            }
            if(x>n)
            {
                temp+=n;
                mp[n]=0;
                vec.pb(n);
                x = sum-temp;
                n--;
            }
        }
        if(sum1 %2==0)
            printf("0\n");
        else
            printf("1\n");
        int sz = vec.size();
        printf("%d",sz);
        for(i=0;i<sz;i++)
            printf(" %d",vec[i]);
        printf("\n");
    }

    return 0;
}
