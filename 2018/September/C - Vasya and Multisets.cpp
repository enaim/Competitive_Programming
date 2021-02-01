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

int ar[110],flag[110],n;


void DIS(int cnt)
{
    int j = 0,i;
    for(i=0;i<n;i++)
    {
        if(flag[ar[i]]==1 && j<cnt)
        {
            printf("B");
            j++;
        }
        else
            printf("A");
    }
    printf("\n");
}

void OddDis(int cnt)
{
    int i,j,ind,indv;
    for(i=0;i<n;i++)
    {
        if(flag[ar[i]]>2)
        {
            ind = i;
            indv = ar[i];
            break;
        }
    }

    j = 0;
    for(i=0;i<n;i++)
    {
        if(flag[ar[i]]==1 && j<cnt)
        {
            printf("B");
            j++;
        }
        else if(i==ind)
        {
            printf("B");
        }
        else
            printf("A");
    }
    printf("\n");
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int dis,more,db,i,x;
    while(1==scanf("%d",&n))
    {
        memset(flag,0,sizeof flag);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            ar[i]=x;
            flag[x]++;
        }
        dis = more = db = 0;
        for(i=1;i<=100;i++)
        {
            if(flag[i]==1)
                dis++;
            if(flag[i]==2)
                db++;
            if(flag[i]>2)
                more++;
        }

        if(dis%2==0 && dis!=0)
        {
            printf("YES\n");
            DIS(dis/2);
            continue;
        }
        if(dis%2!=0 && more==0)
        {
            printf("NO\n");
            continue;
        }
        if(dis%2!=0 && more)
        {
            printf("YES\n");
            OddDis(dis/2);
            continue;
        }
        if(dis==0)
        {
            printf("YES\n");
            for(i=0;i<n;i++)
                printf("A");
            printf("\n");
        }
    }

    return 0;
}
