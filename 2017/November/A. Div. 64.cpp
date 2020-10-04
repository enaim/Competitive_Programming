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
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[110];
    int i,len,cnt,x;
    while(1==scanf("%s",str))
    {
        cnt = 0;
        x = 0;
        len = strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]=='1')
                x = 1;
            if(x==1)
            {
                if(str[i] == '0')
                    cnt++;
            }
        }
        if(cnt>=6)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
