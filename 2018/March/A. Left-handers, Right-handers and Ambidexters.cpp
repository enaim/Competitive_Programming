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

    int a,b,c,x,ans;
    while(3==scanf("%d%d%d",&a,&b,&c))
    {
        if((a==0 && c==0) || (b==0 && c==0))
        {
            cout<<"0"<<endl;
        }
        else if(a>b)
        {
            if(b+c<a)
                printf("%d\n",b+c+b+c);
            else
            {
                x = b+c-a;
                ans = a+a;
                if(x>=2)
                {
                    if(x%2==0)
                        ans+=x;
                    else
                        ans+=(x-1);
                }
                cout<<ans<<endl;
            }
        }
        else if(a<b)
        {
            if(a+c<b)
                printf("%d\n",a+c+a+c);
            else
            {
                x = a+c-b;
                ans = b+b;
                if(x>=2)
                {
                    if(x%2==0)
                        ans+=x;
                    else
                        ans+=(x-1);
                }
                cout<<ans<<endl;
            }
        }
        else
        {
            if(c%2==0)
                cout<<a+b+c<<endl;
            else
                cout<<a+b+c-1<<endl;
        }
    }

    return 0;
}
