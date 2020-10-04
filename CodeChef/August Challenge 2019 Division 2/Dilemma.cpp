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

    int tks,ks=1;
    int cnt,n,i,j;
    char str[100010];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",str);
        n = strlen(str);
        cnt = 0;
        for(i=0;i<n;i++)
            if(str[i]=='1')
                cnt++;
        if(cnt==1)
        {
            printf("WIN\n");
            continue;
        }
        else if(cnt==0)
        {
            printf("LOSE\n");
            continue;
        }
        for(i=0;i<n;i++)
            if(str[i]=='1')
                break;
        for(j=n-1;j>=0;j--)
            if(str[j]=='1')
                break;
        while(i<=j)
        {
            if(str[i]=='1')
            {
                cnt--;
                if(i!=j)
                {
                    if(str[i+1]=='1')
                        cnt--;
                    else
                        cnt++;
                    str[i+1] = (!(str[i+1]-48))+48;
                }
                i++;
            }
            else if(str[j]=='1')
            {
                cnt--;
                if(str[j-1]=='1')
                    cnt--;
                else
                    cnt++;
                if(i!=j)
                    str[j-1] = (!(str[j-1]-48))+48;
                j--;
            }
            if(cnt==1)
                break;
            if(str[i]=='0')
                i++;
            if(str[j]=='0')
                j--;
        }
        if(cnt==1)
            printf("WIN\n");
        else
            printf("LOSE\n");
    }

    return 0;
}
