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

char str1[5010];
char str2[5010];
int mi[5010];
int pos[5010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i;
        scanf("%s%s",str1,str2);
        int n = strlen(str1);
        int m = strlen(str2);
        int flag = 0;

        mi[n-1]=str1[n-1]-'A';
        pos[n-1]=n-1;

        int ch;
        for(i=n-2;i>=0;i--)
        {
            ch = str1[i+1]-'A';
            if(ch<mi[i+1])
            {
                mi[i]=ch;
                pos[i]=i+1;
            }
            else
            {
                mi[i]=mi[i+1];
                pos[i]=pos[i+1];
            }
        }
        for(i=0;i<n-1;i++)
        {
            ch = str1[i]-'A';
            if(ch>mi[i])
            {
                swap(str1[i],str1[pos[i]]);
                break;
            }
        }
        if(strcmp(str1,str2)<0)
            printf("%s\n",str1);
        else
            printf("---\n");
    }

    return 0;
}
