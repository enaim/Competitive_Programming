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

struct node{
    int x,y;
};
node a,b;
int i,n;
char str[100010];
char ans[100010];

void func(int i)
{
    if(str[i]=='S')
        b.y++;
    else
        b.x++;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%s",&n,str);
        a.x = a.y = b.x = b.y = 1;
        i = 0;
        while(i<((2*n)-2))
        {
            if(a.x==b.x && a.y==b.y)
            {
                if(str[i]=='S')
                {
                    ans[i]='E',ans[i+1]='S';
                    a.x++,a.y++;

                    b.y++;
                    func(i+1);
                }
                if(str[i]=='E')
                {
                    ans[i]='S',ans[i+1]='E';
                    a.x++,a.y++;

                    b.x++;
                    func(i+1);
                }
            }
            else
            {
                func(i);
                func(i+1);
                if(b.x==a.x+1 && b.y == a.y+1)
                {
                    if(str[i+1]=='S')
                    {
                        ans[i]='S',ans[i+1]='E';
                        a.x++,a.y++;
                    }
                    else
                    {
                        ans[i]='E',ans[i+1]='S';
                        a.x++,a.y++;
                    }
                }
                else
                {
                    ans[i]='E',ans[i+1]='S';
                    a.x++,a.y++;
                }
            }
            i+=2;
        }
        ans[(2*n)-2]='\0';

        printf("Case #%d: %s\n",ks++,ans);
    }

    return 0;
}
