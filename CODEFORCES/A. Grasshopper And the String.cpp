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
    char str[110];
    int i,len,cnt,mx;

    while(1==scanf("%s",str))
    {
        len = strlen(str);

        mx = 0;
        cnt = 0;
        for(i=0;i<=len;i++)
        {
            if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || str[i]=='Y')
            {
                cnt++;
                if(mx<cnt)
                {
                    mx = cnt;
                }
                cnt=0;
            }
            else
                cnt++;
        }
        if(mx<cnt)
        {
            mx = cnt;
        }

        printf("%d\n",mx);
    }

    return 0;
}
