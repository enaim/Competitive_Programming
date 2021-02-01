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

    int ans,k,a,b,n;
    while(4==scanf("%d%d%d%d",&n,&k,&a,&b))
    {
        ans = 0;
        if(k<a)
        {
            ans = a-k+1;
            if(b!=n)
            {
                ans += (b-a)+1;
            }
        }
        else if(k>b)
        {
            ans = k-b+1;
            if(a!=1)
                ans += (b-a)+1;
        }
        else
        {
            if(a==k)
            {
                if(a!=1)
                    ans += 1;
                if(b!=n)
                    ans += (b-a+1);
            }
            else if(k==b)
            {
                if(b!=n)
                    ans += 1;
                if(a!=1)
                    ans += (b-a+1);
            }
            else
            {
                if(b-k > k-a)
                {
                    if(a!=1)
                        ans+= (k-a)+1;
                    else
                        a = k;
                    if(b!=n)
                        ans += (b-a)+1;
                }
                else
                {
                    if(b!=n)
                        ans+=(b-k)+1;
                    else
                        b = k;
                    if(a!=1)
                        ans+= (b-a)+1;
                }
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
