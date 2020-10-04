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
    char str[150],str1[150],ch;
    int tks,ks=1;
    scanf("%d",&tks);
    gets(str);
    while(tks--)
    {
        int i,x,len,len1;
        map<int,int>mp;
        gets(str);
        gets(str1);
        len = strlen(str);
        len1 = strlen(str1);
        for(i=0;i<len1;i++)
        {
            ch = str1[i];
            if(ch<='Z')
                x = ch + ('a'-'A') - 'a';
            else
                x = ch - 'a';
            mp[x]++;
        }
        for(i=0;i<len;i++)
        {
            ch = str[i];
            if(ch<='Z')
                x = ch + ('a'-'A') - 'a';
            else
                x = ch - 'a';
            if(mp[x]>0)
                mp[x]--;
            else
                break;
        }

        if(i==len)
        {
            printf("Case %d: Yes\n",ks++);
            continue;
        }

        mp.clear();
        for(i=0;i<len;i++)
        {
            ch = str[i];
            if(ch<='Z')
                x = ch + ('a'-'A') - 'a';
            else
                x = ch - 'a';
            mp[x]++;
        }
        for(i=0;i<len1;i++)
        {
            ch = str1[i];
            if(ch<='Z')
                x = ch + ('a'-'A') - 'a';
            else
                x = ch - 'a';
            if(mp[x]>0)
                mp[x]--;
            else
                break;
        }
        if(i==len1)
        {
            printf("Case %d: Yes\n",ks++);
            continue;
        }
        else
            printf("Case %d: No\n",ks++);
    }

    return 0;
}
