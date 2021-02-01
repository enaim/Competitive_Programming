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

    int n,i,cnt,last1,last0;
    char str1[1000010],str2[1000010];

    while(3==scanf("%d%s%s",&n,str1,str2))
    {
        last1 = -100;
        last0 = -500;
        cnt = 0;
        for(i=0;i<n;i++)
        {
            if(str1[i]!=str2[i])
            {
                cnt++;
                if(str1[i]=='1')
                    last1 = i;
                else
                    last0 = i;
                if(abs(last1-last0)==1 && last1 != -100 && last0 != -500)
                    cnt-- ,last1 = -100,last0 = -500;
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
