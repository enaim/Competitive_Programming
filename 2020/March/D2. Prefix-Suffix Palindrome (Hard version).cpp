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

template<class T>T sqr(T a)
{
    return a*a;
}
template<class T> T abs(T x)
{
    if(x<0)
        return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

int f,mx;
char str[1000010];
char temp[1000010];
char text[1000010];
int min(int a, int b)
{
    int res = a;
    if(b < a)
        res = b;
    return res;
}

void findLongestPalindromicString()
{
    int N = strlen(text);
    if(N == 0)
        return;
    N = 2*N + 1; //Position count
    int L[N]; //LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1; //centerPosition
    int R = 2; //centerRightPosition
    int i = 0; //currentRightPosition
    int iMirror; //currentLeftPosition
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
    int diff = -1;

    for (i = 2; i < N; i++)
    {
        iMirror = 2*C-i;
        L[i] = 0;
        diff = R - i;
        if(diff > 0)
            L[i] = min(L[iMirror], diff);
        while ( ((i + L[i]) < N && (i - L[i]) > 0) &&
                ( ((i + L[i] + 1) % 2 == 0) ||
                  (text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] )))
        {
            L[i]++;
        }

        if(L[i] > maxLPSLength)
        {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;

            start = (maxLPSCenterPosition - maxLPSLength)/2;
            end = start + maxLPSLength - 1;
            if(start==0)
            {
                f = 1;
                mx = max(mx,end);
            }
        }

        if (i + L[i] > R)
        {
            C = i;
            R = i + L[i];
        }
    }
    start = (maxLPSCenterPosition - maxLPSLength)/2;
    end = start + maxLPSLength - 1;
    if(start==0)
    {
        f = 1;
        mx = max(mx,end);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",str);
        int n = strlen(str);
        int cnt = 0,i,j;
        for(i=0; i<n/2; i++)
        {
            if(str[i]==str[n-i-1])
            {
                cnt++;
                continue;
            }
            break;
        }
        if(n==1)
        {
            printf("%c\n",str[0]);
            continue;
        }
        if(i==n/2)
        {
            printf("%s\n",str);
            continue;
        }

        int x = 0;
        for(i=cnt; i<n-cnt; i++)
            text[x++]=str[i];
        text[x]='\0';

        f =  0;
        mx = -OO;
        int sz = -OO;
        findLongestPalindromicString();
        int s;
        if(f)
        {
            sz = mx;
            s = cnt;
            int z = 0;
            for(i=0; i<=mx; i++)
                temp[z++] = text[i];
            temp[z]='\0';
        }

        for(i=0; i<x/2; i++)
            swap(text[i],text[x-i-1]);

        f =  0;
        mx = -OO;
        findLongestPalindromicString();

        if(f && mx>sz)
        {
            sz = mx;
            int z = 0;
            for(i=mx; i>=0; i--)
                temp[z++] = text[i];
            temp[z]='\0';
        }

        for(i=0; i<cnt; i++)
            printf("%c",str[i]);

        if(sz != -OO)
            printf("%s",temp);
        else
            printf("%c",str[cnt]);

        for(i=n-cnt; i<n; i++)
            printf("%c",str[i]);
        printf("\n");
    }

    return 0;
}
