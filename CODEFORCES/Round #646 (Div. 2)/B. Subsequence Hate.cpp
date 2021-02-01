#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

int zero[1010];
int one[1010];
char str[1010];
int i,x,a,b,o,z,mn;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",str);
//        cout<<str<<endl;
        int n = strlen(str);
        zero[0]=one[0]=0;
        for(i=0;i<n;i++)
        {
            if(str[i]=='1')
            {
                zero[i+1] = zero[i];
                one[i+1] = one[i] + 1;
            }
            else
            {
                zero[i+1] = zero[i] + 1;
                one[i+1] = one[i];
            }
        }
        o = n - zero[n];
        z = n - one[n];
//        deb(o);
//        deb(z);
        mn = min(o,z);
        for(i=1;i<=n;i++)
        {
            z = i-zero[i];
            o = i-one[i];
            a = (n-i) - (zero[n]-zero[i]);
            b = (n-i) - (one[n]-one[i]);
//            cout<<z<<" "<<o<<" "<<a<<" "<<b<<endl;

            x = o+a;
            mn = min(mn,x);

            x = z+b;
            mn = min(mn,x);
        }
        printf("%d\n",mn);
    }

    return 0;
}
