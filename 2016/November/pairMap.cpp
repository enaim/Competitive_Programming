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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;
typedef pair<int,int>pii;


const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


//    int tks,ks=1;
//    scanf("%d",&tks);
//    while(tks--)
//    {
////        printf("Case %d: ",ks++);
//    }


//    while(1==scanf("",&))
//    {
//        printf("\n");
//    }


    map<pii,int>mp;
    pii a;
    a.first  = 23;
    a.second = 22;
    mp[pii(2,3)] = 3;
    mp[pii(2,3)]++;
    deb(mp[pii(2,3)]);

    string s = "sfdkjsakldf";

    printf("%s",s.c_str());
    deb(s.substr(2,6));

    reverse(s.begin(),s.end());
    deb(s);


    return 0;
}
