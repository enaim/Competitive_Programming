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

char str1[1000010];
char str2[1000010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,flag;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s%s",str1,str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        i = j = 0;
        flag = 0;
        while(j<len2)
        {
            if(str1[i]==str2[j] && i<len1)
                i++;
            else if(str1[i-1]!=str2[j] && str1[i]!=str2[j])
            {
                flag = 0;
                break;
            }
            j++;
            if(i==len1)
                flag  = 1;
        }

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }


    return 0;
}
