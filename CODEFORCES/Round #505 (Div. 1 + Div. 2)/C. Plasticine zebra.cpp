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

    int n,i,j,cnt,mx;
    string str,a,b,c;
    cin>>str;
    str+=str;
    n = str.size();
    i = 0;
    j = 1;
    cnt= 1;
    mx = 0;
    while(i<n-1)
    {
        if(cnt==n/2)
        {
            mx = max(mx,cnt);
            cnt = 1;
        }
        else if(str[i]!=str[j])
        {
            cnt++;
        }
        else
        {
            mx = max(mx,cnt);
            cnt = 1;
        }
        i++;
        j++;
    }
    mx = max(mx,cnt);
    cout<<mx<<endl;

    return 0;
}
