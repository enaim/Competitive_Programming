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

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-10;
const double pi = acos(-1.0);

double ar[100010];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,j,n;
        double current1, current2, cur1, cur2, left, right, mid, time1, time2, speed1, speed2, ans, l;
        scanf("%d%lf",&n,&l);
        for(i=0;i<n;i++)
            scanf("%lf",&ar[i]);
        i = 0;
        j = n-1;
        ans = 0.0;
        speed1 = 1.0;
        speed2 = 1.0;
        current1 = 0.0;
        current2 = l;
        while(i<=j && current1<current2)
        {
            time1 = (ar[i]-current1)/speed1;
            time2 = (current2-ar[j])/speed2;
            if(abs(time1-time2)<=eps)
            {
                ans+=time1;
                current1 = ar[i];
                current2 = current2 - (speed2*time1);
                i++;
                j--;
                speed1+=1.0;
                speed2+=1.0;
            }
            else if(time1<time2)
            {
                ans+=time1;
                current1 = ar[i];
                current2 = current2 - (speed2*time1);
                speed1 += 1.0;
                i++;
            }
            else
            {
                ans+=time2;
                current2 = ar[j];
                current1 = current1 + (speed1*time2);
                speed2 += 1.0;
                j--;
            }
        }
        left = 0.0;
        right = 10000000000.00000;
        mid = 0.0;
        int t = 200;
        if(current1<current2)
        {
            while(t--)
            {
                mid = (left+right)/2.0;
                cur1 = current1 + (mid*speed1);
                cur2 = current2 - (mid*speed2);
                if(abs(cur1-cur2)<=eps)
                    break;
                if(cur1>cur2)
                    right = mid - .0000001;
                else
                    left = mid + 0.0000001;
            }

        }
        ans+=mid;
        printf("%.10lf\n",ans);
    }

    return 0;
}
