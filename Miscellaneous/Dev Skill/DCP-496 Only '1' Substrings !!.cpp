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

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,j,k,x,len,sum=0,cnt=0;
        char str[10010];
        scanf("%s",str);
        len = strlen(str);
        for(i=0;i<=len;i++)
        {
            if(str[i]=='1' && i<len)
                cnt++;
            else if(cnt)
            {
                for(j=cnt;j>=1;j--)
                    sum+=(cnt-j+1);
                cnt = 0;
            }
        }
        cout<<sum<<endl;
    }



    return 0;
}

