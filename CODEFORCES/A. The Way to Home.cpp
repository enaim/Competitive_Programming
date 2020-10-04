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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

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
    int ar[110];
    int n,d,i;
    while(2==scanf("%d%d",&n,&d))
    {
        scanf("%s",str);
        int cnt = 0;
        ar[cnt++] = 1;
        for(i=1;i<n;i++)
            if(str[i]=='1')
                ar[cnt++]=i;
        int x = 0;
        int z = 1;
        int cnt1 = 0;
        for(i=1;i<cnt;i++)
        {
            if(ar[i]-x <= d && ar[i+1]-x<=d && i+1<cnt)
                continue;
            else if(ar[i]-x<=d)
            {
                cnt1++;
                x = ar[i];
            }
            else if(ar[i]-x>d)
            {
                z = 0;
                break;
            }
        }
        if(z)
            printf("%d\n",cnt1);
        else
            printf("-1\n");
    }

    return 0;
}
