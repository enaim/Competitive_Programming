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
    int ar[200010],flag[200010],i,n,x,q;

    while(2==scanf("%d%d",&n,&q))
    {
        memset(flag,0,sizeof flag);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            flag[x]++;
            ar[i]=x;
        }
        if(flag[q]==0 && flag[0]==0)
        {
            printf("NO\n");
            continue;
        }
        if(flag[q]==0 && flag[0]!=0)
        {
            for(i=0;i<n;i++)
            {
                if(ar[i]==0)
                {
                    ar[i]=q;
                    flag[q]++;
                    break;
                }
            }
        }

        for(i=1;i<n;i++)
        {
            if(ar[i]==0)
            {
                ar[i]=ar[i-1];
                flag[ar[i]]++;
            }
        }
        for(i=n-2;i>=0;i--)
        {
            if(ar[i]==0)
            {
                ar[i]=ar[i+1];
                flag[ar[i]]++;
            }
        }
        x = 0;
        priority_queue<int>pq;
        map<int,int>mp;

        for(i=0;i<n;i++)
        {
            if(!pq.empty()&& pq.top()>ar[i])
            {
                x = 1;
                break;
            }
            flag[ar[i]]--;
            if(flag[ar[i]]==0  && !pq.empty() && ar[i]==pq.top())
                pq.pop();
            if(flag[ar[i]])
            {
                if(mp[ar[i]]==0)
                    pq.push(ar[i]);
                mp[ar[i]]++;
            }
        }
        if(x)
            printf("NO\n");
        else
        {
            printf("YES\n");
            for(i=0;i<n;i++)
                printf("%d ",ar[i]);
            printf("\n");
        }
    }

    return 0;
}
