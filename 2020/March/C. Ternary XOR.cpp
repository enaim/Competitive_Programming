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
char str1[100010];
char str2[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int n,i;
        scanf("%d%s",&n,str);
        int f = 0;
        for(i=0;i<n;i++)
        {
            if(str[i]=='0')
            {
                str1[i]='0';
                str2[i]='0';
            }
            else if(str[i]=='2' && f==0)
            {
                str1[i]='1';
                str2[i]='1';
            }
            else if(str[i]=='2' && f==1)
            {
                str1[i]='0';
                str2[i]='2';
            }
            else
            {
                if(f)
                {
                    str1[i]='0';
                    str2[i]='1';
                }
                else
                {
                    f = 1;
                    str1[i]='1';
                    str2[i]='0';
                }
            }
        }
        str1[n]='\0';
        str2[n]='\0';
        printf("%s\n",str1);
        printf("%s\n",str2);
    }

    return 0;
}
