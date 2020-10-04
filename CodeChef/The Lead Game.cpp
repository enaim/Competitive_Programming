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

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1;
    int mx,x,y,a,temp,m,n;
    while(1==scanf("%d",&tks))
    {
        mx = 0;
        m = n = 0;
        while(tks--)
        {
            scanf("%d%d",&x,&y);
            m+=x;
            n+=y;
            temp = abs(m-n);
            if(temp>mx)
            {
                mx = temp;
                if(x>y)
                    a = 1;
                else
                    a = 2;

            }
        }
        printf("%d %d\n",a,mx);
    }

    return 0;
}
