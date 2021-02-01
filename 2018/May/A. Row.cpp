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
    int n,z;
    char str[100010];
    while(2==scanf("%d%s",&n,str))
    {
        z = true;
        if(n==1 && str[0]=='0')
            z = false;
        for(int i=0;i<n-1;i++)
        {
            if(str[i]==str[i+1] && str[i]=='1')
                z = false;
            if(str[i]==str[i+1] && str[i]==str[i+2] && str[i]=='0' && i<n-2)
                z = false;
            if(str[n-2]==str[n-1] && str[n-1]=='0')
                z = false;
            if(str[0]==str[1] && str[0]=='0')
                z = false;
        }
        if(z)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
