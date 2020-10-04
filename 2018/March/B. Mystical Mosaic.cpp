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
    bool row[100],column[100],ans,f1;
    int r,c,i,j,k;
    char str[100][100];

    while(2==scanf("%d%d",&r,&c))
    {
        for(i=0;i<r;i++)
            scanf("%s",str[i]);
        memset(row,true,sizeof row);
        memset(column,true,sizeof column);
        ans = true;
        f1 = true;

        for(i=0;i<r;i++)
        {
            if(row[i]==false)
                    continue;

            row[i]==false;

            for(j=0;j<c;j++)
            {
                if(str[i][j]=='#' && column[j]==false)
                {
                    f1 = false;
                    break;
                }
                else if(str[i][j]=='#')
                    column[j]=false;

            }
            if(!f1)
            {
                ans = false;
                break;
            }
            for(j=i+1;j<r;j++)
            {
                if(row[j]==false)
                    continue;
                if(strcmp(str[i],str[j])==0)
                {
                    row[j]=false;
                }
            }
        }
        if(ans)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
