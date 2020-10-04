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

    map<string,int>mp1,mp;
    mp1["Nikita"]++;
    mp1["Danil"]++;
    mp1["Olya"]++;
    mp1["Slava"]++;
    mp1["Ann"]++;

    char str[110],str1[110];
    string st;
    int cnt,i,k,j,len;
    while(gets(str))
    {
        cnt = 0;
        j = 0;
        len = strlen(str);
        for(i=0;i<len;i++)
        {
            k = 0;
            for(j=i;j<len;j++)
            {
                str1[k] = str[j]; k++;
                str1[k] = '\0';
                st = str1;
                if(mp1[st] != 0)
                {
                    cnt++;
                }
            }
        }
        if(cnt==1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
