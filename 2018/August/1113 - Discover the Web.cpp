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

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        string str,curr;
        printf("Case %d:\n",ks++);
        stack<string>f;
        stack<string>b;
        curr = "http://www.lightoj.com/";
        while(true)
        {
            cin>>str;
            if(str=="QUIT")
                break;
            if(str=="VISIT")
            {
                cin>>str;
                b.push(curr);
                curr=str;
                while(!f.empty())
                    f.pop();
                cout<<curr<<endl;
            }
            if(str=="BACK")
            {
                if(b.empty())
                {
                    printf("Ignored\n");
                    continue;
                }
                f.push(curr);
                curr = b.top();
                b.pop();
                cout<<curr<<endl;
            }
            if(str=="FORWARD")
            {
                if(f.empty())
                {
                    printf("Ignored\n");
                    continue;
                }
                b.push(curr);
                curr = f.top();
                f.pop();
                cout<<curr<<endl;
            }
        }
    }

    return 0;
}
