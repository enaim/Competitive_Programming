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

char Text[1000010];
char Pattern[1000010];
int Prefix[1000010];

void Compute_Prefix_Function(int m)
{
    int i,j;
    j = 0;
    Prefix[0]=0;
    for(i=1;i<m;i++)
    {
        while((j>0) && (Pattern[j] != Pattern[i]))
            j = Prefix[j-1];

        if(Pattern[j] == Pattern[i])
            j = j + 1;

        Prefix[i]=j;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int len1,len2 ,i,j,c1,c2,c11,c12;
    while(2==scanf("%s%s",Text,Pattern))
    {
        c11 = c12 = c1 = c2 = 0;
        len1 = strlen(Text);
        len2 = strlen(Pattern);
        Compute_Prefix_Function(len2);

        for(i=0;i<len1;i++)
            if(Text[i]=='1')
                c1++;
            else
                c2++;

        for(i=0;i<len2;i++)
            if(Pattern[i]=='1')
                c11++;
            else
                c12++;

        if(c11<=c1 && c12<=c2)
        {
            printf("%s",Pattern);
            c1-=c11;
            c2-=c12;
        }
        else
        {
            printf("%s\n",Text);
            return 0;
        }
        c11 = c12 = 0;
        for(i=Prefix[len2-1];i<len2;i++)
        {
            if(Pattern[i]=='1')
                c11++;
            else
                c12++;
        }

        while(c11<=c1 && c12<=c2)
        {
            for(i=Prefix[len2-1];i<len2;i++)
                printf("%c",Pattern[i]);
            c1 -= c11;
            c2 -= c12;
        }
        for(i=1;i<=c1;i++)
            printf("1");
        for(i=1;i<=c2;i++)
            printf("0");
        printf("\n");
    }

    return 0;
}
