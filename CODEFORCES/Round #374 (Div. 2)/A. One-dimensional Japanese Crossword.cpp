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

    vector<int>sz;
    int g,cnt,i,x,n;
    char str[100];
    while(1==scanf("%d",&n))
    {
        sz.clear();
        g=0;
        cnt=0;
        scanf("%s",str);
        for(i=0;i<n;i++)
        {
            if(str[i] == 'B')
            {
                cnt++;
            }
            else if(cnt != 0)
            {
                sz.pb(cnt);
                cnt=0;
            }
        }
        if(cnt != 0)
            sz.pb(cnt);

        x = sz.size();

        printf("%d\n",x);
        for(i=0;i<x;i++)
        {
            if(i== (x-1))
                printf("%d\n",sz[i]);
            else
                printf("%d ",sz[i]);
        }
    }

    return 0;
}
