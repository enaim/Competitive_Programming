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

    int tks,ks=1,len,x;
    char str[20];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",str);
        len = strlen(str);
        x = 0;
        for(int i=0;i<len/2;i++)
        {
            if(str[i]!=str[len-1-i])
                x =1;
        }
        if(x)
            printf("Case %d: No\n",ks++);
        else
            printf("Case %d: Yes\n",ks++);
    }

    return 0;
}
