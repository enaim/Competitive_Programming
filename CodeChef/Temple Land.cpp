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


    int tks,ks=1,n;
    int ar[110];
    scanf("%d",&tks);
    while(tks--)
    {
        bool x = true;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }
        if(n%2!=0)
        {
            if(ar[0]!=1)
                x = false;
            else
            {
                for(int i=1;i<=n/2;i++)
                {
                    if(ar[i]-ar[i-1]!=1)
                    {
                        x = false;
                        break;
                    }
                }
                for(int i=n-1;i>n/2 && x;i--)
                {
                    if(ar[i-1]-ar[i]!=1)
                    {
                        x = false;
                        break;
                    }
                }
            }
        }
        else
            x = false;
        if(x)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
