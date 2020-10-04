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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[100];
    int ar[100];
    int i,b1,b2,cnt;
    while(3==scanf("%s%d%d",str,&b1,&b2))
    {
        int n = strlen(str);
        ll res = 1;
        long long sum = 0;
        for(i=n-1;i>=0;i--)
        {
            if(str[i]>='A' && str[i]<='F')
                sum = sum + (res*(str[i]-'A'+10));
            else
                sum = sum + (res*(str[i]-'0'));
            res*=b1;
        }
        cnt = 0;
        while(sum!=0)
        {
            ar[cnt++]=sum%b2;
            sum/=b2;
        }
        if(cnt>10)
        {
            printf("ERROR\n");
            continue;
        }
        for(i=cnt-1;i>=0;i--)
        {
            if(ar[i]>9)
                printf("%c",ar[i]+('A'-10));
            else
                printf("%d",ar[i]);
        }
        printf("\n");
    }

    return 0;
}
