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
    int roll,marks;
    char str[100];
};

node ar[110];

bool compare(node a, node b)
{
    if(a.marks==b.marks)
        return a.roll<b.roll;
    return a.marks>b.marks;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i,j;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d%s%d",&ar[i].roll,ar[i].str,&ar[i].marks);
        sort(&ar[0],&ar[n],compare);
        printf("Roll | Name       | Marks\n");
        printf("-------------------------\n");
        for(i=0;i<n;i++)
        {
            printf("%4d | ",ar[i].roll);
            printf("%s",ar[i].str);
            for(j=0;j<10-strlen(ar[i].str);j++)
                printf(" ");
            printf(" | %d\n",ar[i].marks);
        }
    }

    return 0;
}
