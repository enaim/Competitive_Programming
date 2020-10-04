#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

char str[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i;
    scanf("%d",&tks);
    while(tks--)
    {
        map<int,char>mp;
        mp[1]='a';
        mp[2]='b';
        mp[3]='c';
        scanf("%s",str);
        int n = strlen(str);
        if(str[0]=='?')
        {
            if(n==1)
                str[0]='a';
            else if(n==2 && str[1]=='?')
                str[0]='a';
            else if(str[1]=='b' || str[1]=='c')
                str[0]='a';
            else if(str[1]=='a' || str[1]=='c')
                str[0]='b';
            else
                str[0]='c';
        }
        if(n==1)
        {
            printf("%s\n",str);
            continue;
        }
        for(i=1;i<n-1;i++)
        {
            if(str[i]=='?' && str[i+1]!='?' && str[i-1]!=str[i+1])
            {
                str[i]=mp[(str[i-1]-'a'+1)^(str[i+1]-'a'+1)];
            }
            else if(str[i]=='?')
            {
                if(str[i-1]=='b' || str[i-1]=='c')
                    str[i]='a';
                else if(str[i-1]=='a' || str[i-1]=='c')
                    str[i]='b';
                else
                    str[i]='c';
            }
        }
        i = n-1;
        if(str[n-1]=='?')
        {
            if(str[i-1]=='b' || str[i-1]=='c')
                str[i]='a';
            else if(str[i-1]=='a' || str[i-1]=='c')
                str[i]='b';
            else
                str[i]='c';
        }
        for(i=1;i<n;i++)
            if(str[i-1]==str[i])
                break;
        if(i!=n)
            printf("-1\n");
        else
            printf("%s\n",str);
    }

    return 0;
}
