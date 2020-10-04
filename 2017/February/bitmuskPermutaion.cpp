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
#define Two(a)  (1<<a)

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
    while(1==scanf("%d",&n))
    {
        for(int mask = 0; mask< Two(n); ++mask)
        {
            int cnt = 0;
            for(int i=0;i<n;i++)
            {
                if(mask & Two(i))
                {
                    cnt++;
                }
            }
        }

    }

    return 0;
}
