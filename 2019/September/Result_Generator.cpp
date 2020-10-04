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

struct node{
    char str[110];
    int penalty,problem;
};

node ar[100];

bool compare(node a, node b)
{
    if(a.problem==b.problem)
        return a.penalty<b.penalty;
    return a.problem>b.problem;
}

int main()
{
    freopen("Penalty.txt","r",stdin);
    freopen("Final_Standings.txt","w",stdout);

    int i;
    for(i=1;i<=77;i++)
        scanf("%s%d%d",ar[i].str,&ar[i].problem,&ar[i].penalty);
    sort(&ar[1],&ar[78],compare);
    for(i=1;i<=77;i++)
        printf("%2d. %6d %10d  %s\n",i,ar[i].problem,ar[i].penalty,ar[i].str);

    return 0;
}
