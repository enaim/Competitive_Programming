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

    int n,i,cnt;
    int l[60];
    bool x;
    char s[60][10];

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d%s",&l[i],s[i]);
        cnt = 0;
        x = true;
        for(i=0;i<n;i++)
        {
            if(cnt == 0 && s[i][0] != 'S')
            {
                x = false;
                break;
            }
            else if(cnt == 20000 && s[i][0]!= 'N')
            {
                x = false;
                break;
            }
            else if(s[i][0] == 'S')
                cnt+=l[i];
            else if(s[i][0] == 'N')
                cnt-=l[i];
            if(cnt > 20000 || cnt <0)
            {
                x = false;
                break;
            }
        }
        if(!x )
            printf("NO\n");
        else if(cnt != 0)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
