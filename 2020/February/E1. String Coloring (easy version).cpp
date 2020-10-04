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

char str[210];
int flag[210];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,j;
    while(1==scanf("%d",&n))
    {
        scanf("%s",str);
        char last = str[0];
        int f = 0;
        for(i=1;i<n;i++)
        {
            if(last>str[i])
            {
                for(j=0;j<i;j++)
                {
                    if(str[j]>str[i] && flag[j]==1)
                    {
                        f = 1;
                        break;
                    }
                }
                if(f)
                    break;
                flag[i]=1;
            }
            else
                last = str[i];
        }
        if(f)
            printf("NO\n");
        else
        {
            printf("YES\n");
            for(i=0;i<n;i++)
                printf("%d",flag[i]);
            printf("\n");
        }
    }

    return 0;
}
