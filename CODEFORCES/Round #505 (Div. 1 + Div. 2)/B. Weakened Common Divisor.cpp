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



const int FLAG_SIZE = 1001000;
const int PRIME_SIZE = 80000;


bool flag[FLAG_SIZE];
int prime[PRIME_SIZE];

struct node{
    int x,y;
};

void sieve()
{
    int ind = 1,i,j;
    double d;

    prime [ ind++ ]  = 2;

    for(i=3;i<FLAG_SIZE;i+=2)
    {
        if(flag[i] == false)
        {
            prime[ind++]=i;

            if(i > FLAG_SIZE/i) ///cause i*i > FLAG_SIZE
                continue;

            for(j=i*i,d=i+i;j<=FLAG_SIZE;j+=d)
                flag[j]=true;
        }
    }
}

node ar[150010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();

    int n,i,j,cnt;
    while(1==scanf("%d",&n))
    {
        set<int>st;
        cin>>ar[0].x>>ar[0].y;
        st.insert(2);
        st.insert(ar[0].x);
        st.insert(ar[0].y);
        for(i=1;i<n;i++)
        {
            cin>>ar[i].x>>ar[i].y;
            if((ar[0].x%ar[i].x==0 || ar[0].y%ar[i].x==0) && ar[i].x %2 !=0)
                st.insert(ar[i].x);
            if((ar[0].x%ar[i].y==0 || ar[0].y%ar[i].y==0) && ar[i].y %2 !=0)
                st.insert(ar[i].y);
        }

        for(j=2;prime[j]<=45000;j++)
        {
            if(ar[0].x % prime[j]==0 || ar[0].y % prime[j]==0)
                st.insert(prime[j]);
        }

        int ans = -1;
        for(auto it : st)
        {
            cnt = 0;
            for(i=0;i<n;i++)
            {
                if(ar[i].x % it==0 || ar[i].y % it==0)
                    cnt++;
                else
                    break;
            }
            if(cnt==n)
            {
                ans = it;
                break;
            }
        }
        if(ans != -1)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }

    return 0;
}
