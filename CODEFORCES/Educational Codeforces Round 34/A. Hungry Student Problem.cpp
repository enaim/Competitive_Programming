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
#define sqr(a)  (a*a)

typedef long long ll;
typedef pair<int,int>pii;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,z,x,temp1,temp2,i;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&x);

        if(x%7==0 || x%3==0 )
            printf("YES\n");
        else if(x<3)
            printf("NO\n");
        else
        {
            z = 0;
            for(i=0;i<40;i++)
            {
                temp1 = 3*i;
                if(temp1>(x-7))
                    break;
                temp2 = x-temp1;
                if(temp2%7==0 && temp2>0)
                {
                    z = 1;
                    break;
                }
            }
            if(z==1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
