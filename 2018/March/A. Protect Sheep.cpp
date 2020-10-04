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

int dr[]={-1,0,0,1};
int dc[]={0,-1,1,0};

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[510][510],str1[510][510];
    int r,c,i,x,cnt,j,k,s,w;

    while(2==scanf("%d%d",&r,&c))
    {
        for(i=0;i<r;i++)
            scanf("%s",str[i]);

        cnt = 0;
        s = 0;
        w = 0;

        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                if(str[i][j]=='.')
                    cnt++;
                if(str[i][j]=='S')
                    s++;
                if(str[i][j]=='W')
                    w++;
                if(str[i][j]=='.')
                    str[i][j]='D';
                str1[i][j] = str[i][j];
            }
        if(s!=0 && w!=r*c && w!=0)
        {
            for(int m=0;m<90;m++)
            {
                for(i=0;i<r;i++)
                {
                    for(j=0;j<c;j++)
                    {
                        if(str[i][j]=='W')
                        {
                            for(k=0;k<4;k++)
                            {
                                if((str[i+dr[k]][j+dc[k]] =='S' && i+dr[k]>=0 && i+dr[k]<r && j+dc[k]>=0 && j+dc[k]<c ))
                                    str[i+dr[k]][j+dc[k]] = 'W';
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(str[i][j]=='S')
                    ans++;
            }
        }
        if(ans == s || s==0 || cnt == r*c || w==0)
        {
            printf("Yes\n");
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    printf("%c",str1[i][j]);
                }
                printf("\n");
            }
        }
        else
            printf("No\n");
    }

    return 0;
}
