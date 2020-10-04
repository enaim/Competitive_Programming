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

    char str1[200010],str2[200010];
    int n,m,i,j,star;
    while(4==scanf("%d%d%s%s",&n,&m,str1,str2))
    {
        if(strcmp(str1,str2)==0 || (n==1 && str1[0]=='*'))
        {
            printf("YES\n");
            continue;
        }
        star = -1;
        for(i=0;i<n;i++)
        {
            if(str1[i]=='*')
                star =  i;
        }
        if(star == -1)
        {
            printf("NO\n");
            continue;
        }
        if(star==n-1)
        {
            j = 0;
            for(i=0;i<n-1;i++)
            {
                if(j==m || str1[i]!=str2[j])
                    break;
                j++;
            }
            if(i!=n-1)
            {
                printf("NO\n");
                continue;
            }
            else
            {
                printf("YES\n");
                continue;
            }

        }
        else if(star==0)
        {
            j = 0;
            for(i=n-1;i>0;i--)
            {
                if(m-j-1>=0 && str1[i]==str2[m-j-1])
                    j++;
                else
                    break;
            }
            if(i==0)
            {
                printf("YES\n");
                continue;
            }
            else
            {
                printf("NO\n");
                continue;
            }
        }
        else
        {
            for(i=0;i<star;i++)
            {
                if(str1[i]!=str2[i] && i<m)
                    break;
            }
            if(i!=star)
            {
                printf("NO\n");
                continue;
            }
            j = 0;
            for(i=n-1;i>star;i--)
            {
                if(m-j-1>=0 && str1[i]==str2[m-1-j] && m-j-1>star-1)
                    j++;
                else
                    break;
            }
            if(i!=star)
            {
                printf("NO\n");
                continue;
            }
            else
            {
                printf("YES\n");
                continue;
            }
        }
    }

    return 0;
}
