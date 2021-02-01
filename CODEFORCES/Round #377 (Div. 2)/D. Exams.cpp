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

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
const int SIZE = 100010;

int s;
int day[SIZE];
int sub[SIZE];
bool clr[SIZE];

bool isPossible(int m)
{
    long long p,i;

    clr[0]=false;
    for(i=1;i<=s;i++)
        clr[i]=true;

    p = 0;
    int passed = 0;
    for(i=m;i>0;i--)
    {
        int x = day[i];
        if(clr[x] == true)
        {
            passed++;
            p+=sub[x];
            clr[x]=false;
        }
        else if(p)
            p--;
    }
    if(p==0)
        return passed == s;

    return false;
}

int Binary_Search(int first,int last)
{
    int mid;
    while(first<last)
    {
        mid = (first + last) / 2;

        if(isPossible(mid))
            last = mid;
        else
            first = mid+1;
    }

    return first;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int sum,i,ans,n;

    while(2==scanf("%d%d",&n,&s))
    {
        sum = 0;
        for(i=1;i<=n;i++)
            scanf("%d",&day[i]);
        for(i=1;i<=s;i++)
            scanf("%d",&sub[i]);

        if(isPossible(n))
            ans = Binary_Search(1,n);
        else
            ans = -1;

        printf("%d\n",ans);
    }

    return 0;
}
