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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

    char str[100],s[100];
    int n,k,i;
    while(1==scanf("%s",str))
    {
        for(i=0;i<90;i++)
            s[i]='A';
        n = strlen(str);
        k = n-1;
        if(k%2!=0)
            k--;
        int f = 1;
        for(i=0;i<n;i++)
        {
            s[k]=str[i];
            if(k==0)
                k=1,f=0;
            else if(f==1)
                k-=2;
            else
                k+=2;
        }
        s[n]='\0';
        printf("%s\n",s);
    }

    return 0;
}
