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

    int cnt1,cnt0,i,k,n;
    char str[100010],str1[100010];
    while(1==scanf("%s",str))
    {
        cnt1= cnt0 = 0;
        n = strlen(str);
        k = n-1;
        for(i=n-1;i>=0;i--)
        {
            if(str[i]=='0')
                cnt0++;
            if(str[i]=='1')
                cnt1++;
            if(str[i]=='2')
            {
                while(cnt0)
                {
                    str1[k] = '0';
                    k--;
                    cnt0--;
                }
                str1[k]='2';
                k--;
                cnt0 = 0;
            }
        }
        while(cnt1)
        {
            str1[k]='1';
            k--;
            cnt1--;
        }
        while(k>-1)
        {
            str1[k]='0';
            k--;
        }
        str1[n]='\0';
        printf("%s\n",str1);
    }

    return 0;
}
