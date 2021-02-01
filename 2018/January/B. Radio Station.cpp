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

 int cnt[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[2010][100];
    char ar[2010][100];
    int i,n,m,j;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=0;i<n+m;i++)
        {
            scanf("%s",str[i]);
            gets(ar[i]);
            if(i<n)
            {
                int len = strlen(ar[i]);
                ar[i][len]=';';
                ar[i][len+1]='\0';
            }
        }
        for(i=n;i<n+m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(strcmp(ar[i],ar[j])==0)
                    printf("%s%s #%s\n",str[i],ar[i],str[j]);
            }
        }
    }


    return 0;
}
