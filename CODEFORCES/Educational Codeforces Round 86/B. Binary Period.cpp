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

char str[110];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,z,o;
        scanf("%s",str);
        int n = strlen(str);
        z = o = 0;
        for(i=0;i<n;i++)
        {
            if(str[i]=='0')
                z++;
            else
                o++;
        }
        if(z==n || o==n)
        {
            printf("%s\n",str);
            continue;
        }
        if(str[0]=='0')
        {
            for(i=0;i<n*2;i++)
            {
                if(i%2==0)
                    printf("0");
                else
                    printf("1");
            }
        }
        else
        {
            for(i=0;i<n*2;i++)
            {
                if(i%2==0)
                    printf("1");
                else
                    printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}
