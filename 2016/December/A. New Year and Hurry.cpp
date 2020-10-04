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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,k;
    while(2==scanf("%d%d",&n,&k))
    {
        int x = 240-k;
        int cnt = 0;
        for(int i=1;i<=10;i++)
        {
            if(i*5<=x && i<=n)
            {
                cnt++;
                x -= (i*5);
            }
            else
                break;
        }

        printf("%d\n",cnt);
    }

    return 0;
}
