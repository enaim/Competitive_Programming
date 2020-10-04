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

struct node{
    string str;
    int val;
};

bool cmp(node a,node b)
{
    if(a.str==b.str)
        return a.val<b.val;
    return a.str<b.str;

}

node ar[1010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int fl[10],mn,n,i;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<10;i++)
            fl[i]=OO;

        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i].val);
            cin>>ar[i].str;
            sort(ar[i].str.begin(),ar[i].str.end());
        }
        sort(&ar[0],&ar[n],cmp);

        for(i=0;i<n;i++)
        {
            if(ar[i].str=="A")
                fl[1]=min(ar[i].val,fl[1]);
            if(ar[i].str=="B")
                fl[2]=min(ar[i].val,fl[2]);
            if(ar[i].str=="C")
                fl[3]=min(ar[i].val,fl[3]);
            if(ar[i].str=="AB")
                fl[4]=min(ar[i].val,fl[4]);
            if(ar[i].str=="BC")
                fl[5]=min(ar[i].val,fl[5]);
            if(ar[i].str=="AC")
                fl[6]=min(ar[i].val,fl[6]);
            if(ar[i].str=="ABC")
                fl[7]=min(ar[i].val,fl[7]);
        }

        mn = OO;
        if(fl[1]!=OO && fl[2]!=OO && fl[3] != OO)
            mn = min(mn,fl[1]+fl[2]+fl[3]);

        if(fl[1]!=OO && fl[5]!=OO)
            mn = min(mn,fl[1]+fl[5]);
        if(fl[2]!=OO && fl[6]!=OO)
            mn = min(mn,fl[2]+fl[6]);
        if(fl[3]!=OO && fl[4]!=OO)
            mn = min(mn,fl[3]+fl[4]);

        if(fl[4]!=OO && fl[5]!=OO)
            mn = min(mn,fl[4]+fl[5]);
        if(fl[4]!=OO && fl[6]!=OO)
            mn = min(mn,fl[4]+fl[6]);


        if(fl[5]!=OO && fl[6]!=OO)
            mn = min(mn,fl[5]+fl[6]);

        if(fl[7] != OO)
            mn = min(mn,fl[7]);
    if(mn!=OO)
        cout<<mn<<endl;
    else
        cout<<"-1"<<endl;
    }

    return 0;
}
