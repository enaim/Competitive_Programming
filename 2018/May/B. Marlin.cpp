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
    int n,k,i,j,x,cnt;
    while(2==scanf("%d%d",&n,&k))
    {
        if(k==0)
        {
            printf("YES\n");
            for(i=0;i<4;i++)
            {
                for(j=0;j<n;j++)
                    printf(".");
                printf("\n");
            }
            continue;
        }
        if(k%2==1)
        {
            printf("YES\n");
            cnt = 1;
            for(j=0;j<4;j++)
            {
                for(i=0;i<n;i++)
                {
                    if(j==1)
                    {
                        char str[1000];
                        for(int h=0;h<n;h++)
                            str[h]='.';
                        str[n]='\0';
                        str[n/2]='#';
                        int a = 1;
                        while(cnt<k && cnt<n-3)
                        {
                            cnt+=2;
                            str[(n/2)-a] = '#';
                            str[(n/2)+a] = '#';
                            a++;
                        }
                        printf("%s",str);
                        break;
                    }
                    if(j==2 && cnt<k)
                    {
                        char str[1000];
                        for(int h=0;h<n;h++)
                            str[h]='.';
                        str[n]='\0';
                        str[n-2]='#';

                        int a = 1;
                        cnt++;
                        while(cnt<k)
                        {
                            str[a]='#';
                            cnt++;
                            a++;
                        }
                        printf("%s",str);
                        break;
                    }
                        else
                            printf(".");
                }
                    printf("\n");
            }
        }
        else
        {
            x = k/2;
            if(x>n-2)
            {
                printf("NO\n");
                continue;
            }
            printf("YES\n");

            for(j=0;j<4;j++)
            {
                cnt = 0;
                for(i=0;i<n;i++)
                {
                    if(j==0 || j==3 || i==0 || i==n-1)
                        printf(".");
                    else
                    {
                        if(x>cnt)
                            printf("#");
                        else
                            printf(".");
                        cnt++;
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}
