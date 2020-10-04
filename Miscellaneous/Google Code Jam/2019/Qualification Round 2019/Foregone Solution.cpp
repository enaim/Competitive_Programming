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
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

    char str[110],str1[110],str2[110],temp[110],f;
    int tks,ks=1,i,cnt,len;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",&str);
        len = strlen(str);
        cnt = 0;
        for(i=len-1;i>=0;i--)
        {
            if(str[i]=='4')
                str1[cnt]='3',str2[cnt]='1';
            else
                str1[cnt]=str[i],str2[cnt]='0';
            cnt++;
        }
        str1[cnt]='\0';
        str2[cnt]='\0';
        for(i=0;i<len/2;i++)
            swap(str1[i],str1[len-i-1]);
        for(i=0;i<len/2;i++)
            swap(str2[i],str2[len-i-1]);

        f = -1;
        for(i=0;i<len;i++)
            if(str2[i]=='0')
                f = i;
            else
                break;
        cnt = 0;
        for(i=f+1;i<len;i++)
            temp[cnt++]=str2[i];
        temp[cnt]='\0';

        printf("Case #%d: %s %s\n",ks++,str1,temp);
    }

    return 0;
}
