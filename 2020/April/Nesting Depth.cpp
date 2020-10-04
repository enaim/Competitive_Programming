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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[110];
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",str);
        int n = strlen(str);
        string ans = "";
        int open = 0;
        int i;
        for(i=0;i<n;i++)
        {
            int x = str[i]-'0';

            if(open<x)
            {
                while(open!=x)
                    ans+="(",open++;
            }
            else
            {
                while(open!=x)
                    ans+=")",open--;
            }
            int k,j = i;
            while(j<n)
            {
                if(str[j]==str[i])
                    j++;
                else
                    break;
            }
            for(k=i;k<j;k++)
                ans+=str[k];

            i = j-1;
        }
        while(open)
            ans+=")",open--;

        printf("Case #%d: ",ks++);
        cout<<ans<<endl;
    }

    return 0;
}
