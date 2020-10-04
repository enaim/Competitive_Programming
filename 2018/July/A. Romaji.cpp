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

    char str[110];
    int i;
    while(1==scanf("%s",str))
    {
        int z = 1;
        int x = 0;
        for(i=0;i<strlen(str);i++)
        {
            if(str[i] !='a' && str[i] !='e' && str[i] !='i' && str[i] !='o' && str[i] !='u')
            {
                if(x==1 && str[i-1]!='n')
                {
                    z = 0;
                    break;
                }
                x = 1;
            }
            else
                x = 0;
        }
        i = i-1;
        if(z==0 || (str[i] !='a' && str[i] !='e' && str[i] !='i' && str[i] !='o' && str[i] !='u' && str[i] !='n'))
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
