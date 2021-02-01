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


    int tks,ks=1,res,ans,i,z,g,b,u,n,l;
    int ar[1010];

    scanf("%d",&tks);
    while(tks--)
    {
        g = b = u = z = ans = 0; 
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        for(i=0;i<n-1;i++)
        {
            if(ar[i] != ar[i+1])
                break;
        }
        if(i==n-1)
            u = 1;

        if(u!=1)
        {
            for(i=0;i<n-1;i++)
            {
                if(ar[i]<ar[i+1])
                    break;
            }
            if(i == n-1)
                b = 1;
        }

        
        if(u!=1 && b!=1)
        {
            for(i=0;i<n-1;i++)
            {
                if(ar[i]>ar[i+1])
                    break;
            }
            if(i == n-1)
                g = 1;
        }
        

        if(g!=1 && b!=1 && u!=1)
        {
            for(i=1;i<n-1;i++)
            {
                if(ar[i]>ar[i-1] && ar[i]>ar[i+1])
                {
                    if(z==0)
                    {
                        l = i;
                        z = 1;
                    }
                    else
                    {
                        res = i-l-1;

                        if(res>ans)
                            ans = res;
                        l = i;
                    }
                }
            }
        }

        if(g==1)        
            printf("allGoodDays\n");
        else if(b==1)   
            printf("allBadDays\n");
        else if(u==1)   
            printf("neutral\n");
        else if(ans!=0) 
            printf("%d\n",ans);
        else            
            printf("none\n");

    }


    return 0;
}
