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

char str1[2000010];
char str2[2000010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int cross,cnt1,cnt2,sum1,sum2,n,f,i;
    while(1==scanf("%d",&n))
    {
        cnt1 = cnt2 = sum1 = sum2 = cross = 0;
        scanf("%s%s",str1,str2);
        for(i=0;i<2*n;i++)
        {
            if(str1[i]=='1' && str2[i]=='1')
                cross++;
            else if(str1[i]=='1')
                cnt1++;
            else if(str2[i]=='1')
                cnt2++;
        }
        f = 1;
        while(cross)
        {
            if(f)
                sum1++,f=0;
            else
                sum2++,f=1;
            cross--;
        }

        if((cnt1==0 && cnt2==0 && cross==0) || (cross==2*n) || (cross%2==0 && cnt1==0 && cnt2==0))
            printf("Draw\n");
        else if(cnt2==0 && sum1 + cnt1 - 1 == sum2 && cnt1 != 1)
            printf("Draw\n");
        else if(sum2+cnt2-1==sum1+cnt1 || sum2+cnt2==sum1+cnt1)
            printf("Draw\n");
        else if(sum1+cnt1>sum2+cnt2)
            printf("First\n");
        else
            printf("Second\n");
    }

    return 0;
}
