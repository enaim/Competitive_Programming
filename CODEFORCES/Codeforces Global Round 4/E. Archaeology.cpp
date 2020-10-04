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

char ar1[1000010];
char ar2[1000010];
char str[1000010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%s",str))
    {
        int cnt1 = 0,cnt2 = 0,i,j;
        int n = strlen(str);
        if(n<=3)
        {
            printf("%c\n",str[0]);
            continue;
        }
        i = 0;
        j = n-1;
        while(i<=j)
        {
            if(abs(cnt1-cnt2)==1)
                break;
            if(str[i]==str[j])
            {
                ar1[cnt1++]=str[i];
                if(i!=j)
                    ar2[cnt2++]=str[j],j--;
                i++;
            }
            else if(i<=j-1 && str[i]==str[j-1])
            {
                ar1[cnt1++]=str[i];
                if(i!=j-1)
                    ar2[cnt2++]=str[j-1],j-=2;
                i++;
            }
            else if(i+1<=j && str[i+1]==str[j])
            {
                ar1[cnt1++]=str[i+1];
                if(i+1!=j)
                    ar2[cnt2++]=str[j],j--;
                i+=2;
            }
            else if(i+1<=j-1 && str[i+1]==str[j-1])
            {
                ar1[cnt1++]=str[i+1];
                if(i+1!=j-1)
                    ar2[cnt2++]=str[j-1],j-=2;
                i+=2;
            }
            else
                break;
        }
        ar1[cnt1]='\0';
        ar2[cnt2]='\0';
        for(i=0;i<cnt2/2;i++)
            swap(ar2[i],ar2[cnt2-i-1]);
        printf("%s%s\n",ar1,ar2);
    }

    return 0;
}
