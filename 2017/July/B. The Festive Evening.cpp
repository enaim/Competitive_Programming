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

    int n,k,x,temp,ar[30],tmp[30],i,cnt;
    char str[1000010];

    while(2==scanf("%d%d",&n,&k))
    {
        for(i=0;i<30;i++)
            tmp[i] = 0;
        scanf("%s",str);

        for(i=1;i<=n;i++)
        {
            x = str[i-1]-'A';
            ar[x] = i;
        }

        cnt = 0;
        temp = 1;
        for(i=1;i<=n;i++)
        {
            x = str[i-1]-'A';
            if(tmp[x] == 0)
            {
                cnt++;
                tmp[x] = 1;
            }

            if(cnt>k)
            {
                temp = 0;
                break;
            }

            if(ar[x] == i)
                cnt--;
        }
        if(temp == 1)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
