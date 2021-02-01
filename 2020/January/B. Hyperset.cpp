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

string str[1600],temp;
map<string,int>mp;
int i,j,k,l,n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin>>n>>k;

    for(i=0;i<n;i++)
    {
        cin>>str[i];
        mp[str[i]]=i+1;
    }
    ll sum = 0LL;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            temp="";
            for(l=0;l<k;l++)
            {
                if(str[i][l]==str[j][l])
                    temp+=str[i][l];
                else
                {
                    if((str[i][l]=='S' && str[j][l]=='T') || (str[i][l]=='T' && str[j][l]=='S'))
                        temp+='E';
                    if((str[i][l]=='S' && str[j][l]=='E') || (str[i][l]=='E' && str[j][l]=='S'))
                        temp+='T';
                    if((str[i][l]=='E' && str[j][l]=='T') || (str[i][l]=='T' && str[j][l]=='E'))
                        temp+='S';
                }
            }
            if(mp.find(temp)!=mp.end())
            {
                if(mp[temp]>j+1)
                    sum++;
            }
        }
    }
    cout<<sum<<endl;

    return 0;
}
