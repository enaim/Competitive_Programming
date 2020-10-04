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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int a,b,c,f;
        scanf("%d%d%d",&a,&b,&c);
        string str = "";
        f = 0;
        while(c)
        {
            if(f==0)
                str = str+"11",c--,f=1;
            else
                str = str+"1",c--;
        }
        if(b)
        {
            if(str.size()==0)
                str = "10";
            else
            {
                if(a)
                {
                    f = 0;
                    while(a)
                    {
                        if(f==0)
                            str+="00",a--,f=1;
                        else
                            str+="0",a--;
                    }
                }
                else
                    str = str + "0";
            }
            b--;
            while(a)
                str+="0",a--;

            f = 0;
            while(b)
            {
                if(f==0)
                    str = str+"1",f=1;
                else
                    str = str+"0",f=0;
                b--;
            }
        }
        f = 0;
        while(a)
        {
            if(f==0)
                str+="00",a--,f=1;
            else
                str+="0",a--;
        }
        cout<<str<<endl;
    }

    return 0;
}
