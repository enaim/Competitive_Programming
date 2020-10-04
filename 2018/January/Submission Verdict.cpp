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

    char str[100];
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",str);
        if(str[0]=='a')
            printf("Accepted\n");
        if(str[0]=='w')
            printf("Wrong Answer\n");
        if(str[0]=='r')
            printf("Run Time Error\n");
        if(str[0]=='t')
            printf("Time Limit Exceeded\n");
    }

    return 0;
}
