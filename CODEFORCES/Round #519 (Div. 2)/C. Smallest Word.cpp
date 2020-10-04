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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

    int ar[1010],i,len;

    string str;
    cin>>str;
    len = str.size();

    for(i=1;i<len;i++)
    {
        if(str[i] != str[i-1])
            break;
    }
    if(i==len)
    {
        for(i=0;i<len;i++)
            printf("0 ");
        return 0;
    }

    ar[0]=0;
    for(i=1;i<len;i++)
    {
        if(str[i]=='a' && str[i-1]=='b' && str[0]=='a')
        {
            reverse(str.begin(),str.begin()+i);
            ar[i-1]=1;
            i--;
        }
        else if(str[i]=='a' && i+1==len)
        {
            ar[i]=1;
            reverse(str.begin(),str.begin()+i+1);
        }
        else if(str[i]=='a' && str[i+1]=='b')
        {
            ar[i]=1;
            reverse(str.begin(),str.begin()+i+1);
        }
        else
            ar[i]=0;
    }

    for(i=0;i<len;i++)
        printf("%d ",ar[i]);

    return 0;
}
