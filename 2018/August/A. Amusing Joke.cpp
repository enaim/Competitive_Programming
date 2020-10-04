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
    int l1,l2,l3,i,x;
    char str1[110],str2[110],str3[110];
    int ar[110];
    while(3==scanf("%s%s%s",str1,str2,str3))
    {
        l1 = strlen(str1);
        l2 = strlen(str2);
        l3 = strlen(str3);
        for(i=0;i<110;i++)
            ar[i]=0;

        for(i=0;i<l1;i++)
            ar[str1[i]]++;
        for(i=0;i<l2;i++)
            ar[str2[i]]++;
        for(i=0;i<l3;i++)
            ar[str3[i]]--;
        x = 1;
        for(i=0;i<110;i++)
        {
            if(ar[i]!=0)
                x = 0;
        }
        if(x)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
