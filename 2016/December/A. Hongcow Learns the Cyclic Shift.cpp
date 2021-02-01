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

    char temp,str[100],str1[60];
    int i,j,len,cnt;
    map<string,int>mp;

    while(1==scanf("%s",str))
    {
        mp.clear();
        len = strlen(str);
        cnt = 0;
        for(i=0;i<len;i++)
        {
            temp = str[len-1];
            for(j=len-1;j>0;j--)
            {
                str[j]=str[j-1];
            }
            str[j]=temp;
            str[len]='\0';
            if(mp[str] == 0)
            {
                mp[str]++;
                cnt++;
            }
        }

        printf("%d\n",cnt);
    }

    return 0;
}
