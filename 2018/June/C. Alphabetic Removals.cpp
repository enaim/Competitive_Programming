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

char str[400010];
int ar[30];
int clr[400010];
int i,j,k,n,sum,x;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&k))
    {
        scanf("%s",str);
        for(i=0;i<n;i++)
            ar[str[i]-'a']++;
        sum = 0;
        for(i=0;i<26;i++)
        {
            sum+=ar[i];
            if(sum>=k)
                break;
        }
        sum-=ar[i];
        x = k - sum;
        for(j=0;j<n;j++)
        {
            if(str[j]=='a'+i && x)
            {
                clr[j] = 1 ;
                x--;
            }
        }
        for(j=0;j<n;j++)
        {
            if(clr[j]==1 || str[j]<='a'+i-1)
                continue;
            printf("%c",str[j]);
        }
        printf("\n");
    }

    return 0;
}
