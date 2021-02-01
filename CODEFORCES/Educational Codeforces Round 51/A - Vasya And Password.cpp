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
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

    int tks,ks=1,i,l,u,d,dl,ul,ll,n;
    char str[110];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",str);
        n = strlen(str);
        d = u = l = 0;
        for(i=0;i<n;i++)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                d++;
                dl = i;
            }
            if(str[i]>='A' && str[i]<='Z')
                u++ , ul = i;
            if(str[i]>='a' && str[i]<='z')
                l++ , ll = i;
        }

        if(d && u && l)
        {
            printf("%s\n",str);
            continue;
        }
        if(d)
        {
            if(u)
            {
                for(i=0;i<n;i++)
                {
                    if(i!=dl && i!= ul)
                    {
                        str[i]='a';
                        break;
                    }
                }
            }
            else if(l)
            {
                for(i=0;i<n;i++)
                {
                    if(i!=dl && i!= ll)
                    {
                        str[i]='A';
                        break;
                    }
                }
            }
            else
            {
                str[0]='a';
                str[1]='A';
            }
        }
        else if(u)
        {
            if(d)
            {
                for(i=0;i<n;i++)
                {
                    if(i!=dl && i!= ul)
                    {
                        str[i]='a';
                        break;
                    }
                }
            }
            else if(l)
            {
                for(i=0;i<n;i++)
                {
                    if(i!=ul && i!= ll)
                    {
                        str[i]='9';
                        break;
                    }
                }
            }
            else
            {
                str[0]='a';
                str[1]='9';
            }
        }
        else
        {
            str[0]='A';
            str[1]='9';
        }
        printf("%s\n",str);
    }

    return 0;
}
