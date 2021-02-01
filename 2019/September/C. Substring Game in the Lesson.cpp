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

int flag[30];
char str[500010];
int ar[500010];
int i,n,j,x;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%s",str))
    {
        n = strlen(str);
        for(i=0;i<n;i++)
        {
            ar[i]=0;
            x = str[i]-'a';
            flag[x]++;
            if(i==0)
                continue;
            for(j=0;j<x;j++)
                if(flag[j])
                {
                    ar[i]=1;
                    break;
                }
        }
        for(i=0;i<n;i++)
        {
            if(ar[i])
                printf("Ann\n");
            else
                printf("Mike\n");
        }
    }

    return 0;
}
