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
    while(1==scanf("%s",str))
    {
        int len  = strlen(str);
        int cnt1 = 0;
        int cnt2 = 0;
        bool temp = true;

        for(int i=0;i<len;i++)
        {
            if(str[i] == '1')
            {
                cnt1++;
                cnt2 = 0;
            }
            else
            {
                cnt2++;
                cnt1 = 0;
            }

            if(cnt1 == 7 || cnt2 == 7)
            {
                temp  = false;
                break;
            }
        }

        if(temp == false)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
