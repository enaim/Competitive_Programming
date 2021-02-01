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
    int n,a,b,cnt,i;
    char str[200010];
    while(3==scanf("%d%d%d",&n,&a,&b))
    {
        scanf("%s",str);
        for(i=0;i<n;i++)
        {
            if(str[i]=='.')
            {
                if((str[i-1]=='*' && i>0) || i==0)
                {
                    if(a>=b && a)
                    {
                        str[i]='a';
                        a--;
                    }
                    else if(b)
                    {
                        str[i]='b';
                        b--;
                    }
                }
                else if(str[i-1]=='.')
                {
                    if(a)
                    {
                        str[i]='a';
                        a--;
                    }
                    else if(b)
                    {
                        str[i]='b';
                        b--;
                    }

                }
                else if(str[i-1]=='a')
                {
                    if(b)
                    {
                        str[i]='b';
                        b--;
                    }
                }
                else if(a)
                {
                    str[i]='a';
                    a--;
                }
            }
        }
        cnt = 0;
        for(i=0;i<n;i++)
            if(str[i]=='a' || str[i]=='b')
                cnt++;
        printf("%d\n",cnt);
    }

    return 0;
}
