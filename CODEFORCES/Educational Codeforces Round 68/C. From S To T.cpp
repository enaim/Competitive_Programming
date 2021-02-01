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

string s,t,p,str;

int i,j,len1,len2,len3,len4,cnt,flag;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        s.clear();p.clear();t.clear();str.clear();
        cin>>s>>t>>p;

        if(s==t)
        {
            printf("YES\n");
            continue;
        }
        len1 = s.size();
        len2 = t.size();
        len3 = p.size();
        i = 0;
        j = 0;
        flag = 0;
        cnt = 0;

        while(i<len1 && j<len2)
        {
            if(s[i]==t[j])
                i++;
            else
                str += t[j];
            j++;
            if(i==len1)
                flag = 1;
        }
        for(i=j;i<len2;i++)
            str += t[i];
        sort(str.begin(),str.end());
        sort(p.begin(),p.end());
//        cout<<endl<<flag<<endl;
//        cout<<str<<" "<<p<<endl;
        if(flag)
        {
            len4 = str.size();
            flag = 0;
            i = j = 0;
            while(i<len4 && j<len3)
            {
                if(str[i]==p[j])
                    i++;
                j++;
                if(i==len4)
                    flag = 1;
            }
        }
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
