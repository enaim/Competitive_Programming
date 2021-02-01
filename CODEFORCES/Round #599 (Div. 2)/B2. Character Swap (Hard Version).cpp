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
    int a,b;
};
node temp,ans[110];

char str1[110];
char str2[110];
int ar[30];
int i,j,x,y,ok,n,k,c;

void func1()
{
    for(j=i+1;j<n;j++)
    {
        if(str1[j]=='a'+k)
        {
            swap(str1[j],str2[i]);
            temp.a = j;
            temp.b = i;
            ans[c++] = temp;
            ok = 1;
            break;
        }
    }
    return;
}


void func2()
{
    for(j=i+1;j<n;j++)
    {
        if(str2[j]=='a'+k)
        {
            swap(str2[j],str1[j]);
            temp.a = j;
            temp.b = j;
            ans[c++] = temp;
            swap(str2[i],str1[j]);
            temp.a = j;
            temp.b = i;
            ans[c++] = temp;
            ok = 1;
            break;
        }
    }
    return;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(ar,0,sizeof ar);
        scanf("%d",&n);
        scanf("%s%s",str1,str2);

        ok = 1;
        for(i=0;i<n;i++)
        {
            x = str1[i]-'a';
            y = str2[i]-'a';
            ar[x]++;
            ar[y]++;
        }
        for(i=0;i<26;i++)
        {
            if(ar[i]%2!=0)
            {
                ok = 0;
                break;
            }
        }
        if(ok==0)
        {
            printf("NO\n");
            continue;
        }
        c = 0;
        for(i=0;i<n;i++)
        {
            ok = 0;
            if(str1[i]!=str2[i])
            {
                k = str1[i]-'a';
                func1();
                if(ok)
                    continue;
                func2();
                if(ok)
                    continue;
            }
        }
        printf("YES\n%d\n",c);
        for(i=0;i<c;i++)
            printf("%d %d\n",ans[i].a+1,ans[i].b+1);
    }

    return 0;
}
