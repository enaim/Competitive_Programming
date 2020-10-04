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

int z;

void func1(char str[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(str[i]=='?')
        {
            z = 1;
            if((str[i-1]!='C' && str[i+1]!='C') && i-1>=0 && i+1<n)
                str[i]='C';
            else if((str[i-1]!='M' && str[i+1]!='M') && i-1>=0 && i+1<n)
                str[i]='M';
            else if((str[i-1]!='Y' && str[i+1]!='Y') && i-1>=0 && i+1<n)
                str[i]='Y';
            else if(str[i-1]!='C' && i+1==n && i-1>=0)
                str[i]='C';
            else if(str[i-1]!='M' && i+1==n && i-1>=0)
                str[i]='M';
            else if(str[i-1]!='Y' && i+1==n && i-1>=0)
                str[i]='Y';
            else if(str[i+1]!='C' && i==0 && i+1<n)
                str[i]='C';
            else if(str[i+1]!='M' && i==0 && i+1<n)
                str[i]='M';
            else if(str[i+1]!='Y' && i==0 && i+1<n)
                str[i]='Y';
        }
    }
}


void func2(char str[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(str[i]=='?')
        {
            if((str[i-1]!='Y' && str[i+1]!='Y') && i-1>=0 && i+1<n)
                str[i]='Y';
            else if((str[i-1]!='M' && str[i+1]!='M') && i-1>=0 && i+1<n)
                str[i]='M';
            else if((str[i-1]!='C' && str[i+1]!='C') && i-1>=0 && i+1<n)
                str[i]='C';
            else if(str[i-1]!='Y' && i+1==n && i-1>=0)
                str[i]='Y';
            else if(str[i-1]!='M' && i+1==n && i-1>=0)
                str[i]='M';
            else if(str[i-1]!='C' && i+1==n && i-1>=0)
                str[i]='C';
            else if(str[i+1]!='Y' && i==0 && i+1<n)
                str[i]='Y';
            else if(str[i+1]!='M' && i==0 && i+1<n)
                str[i]='M';
            else if(str[i+1]!='C' && i==0 && i+1<n)
                str[i]='C';
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[110],str1[110];
    int i,n;
    bool ans;
    while(1==scanf("%d",&n))
    {
        z = 0;
        ans = true;
        scanf("%s",str);
        if(n==1 && str[0]!='?')
        {
            printf("No\n");
            continue;
        }
        else if(n==1)
        {
            printf("Yes\n");
            continue;
        }
        for(i=0;i<n-1;i++)
        {
            str1[i]=str[i];
            if(str[i]==str[i+1] && str[i]!='?')
                ans = false;
        }
        str1[i]=str[i];
        str1[i+1]='\0';
        if(ans == false)
        {
            printf("No\n");
            continue;
        }

        func1(str,n);
        func2(str1,n);

        if(strcmp(str1,str)==0)
            ans = false;
        if(ans == false)
            printf("No\n");
        else
            printf("Yes\n");
    }

    return 0;
}
