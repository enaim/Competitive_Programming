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

string ans;
string first[110];
string last[110];
string str[110];
set<char>st;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tks,ks=1;
    cin>>tks;
    while(tks--)
    {
        int i,j,k,t,n;
        ans.clear();
        ans="";
        for(i=0;i<10000;i++)
            ans+="*";

        cin>>n;
        for(i=0;i<n;i++)
        {
            first[i].clear();
            first[i]="";
            last[i].clear();
            last[i]="";
            str[i].clear();
            str[i]="";
        }
        for(i=0;i<n;i++)
            cin>>str[i];
        for(i=0;i<n;i++)
        {
            int sz = str[i].size();
            for(j=0;j<sz;j++)
            {
                if(str[i][j]=='*')
                    break;
                first[i]+=str[i][j];
            }
            string temp="";
            for(k=j+1;k<sz;k++)
                temp+=str[i][k];

            str[i]=temp;
        }
        for(i=0;i<n;i++)
        {
            int sz = str[i].size();
            for(j=sz-1;j>=0;j--)
            {
                if(str[i][j]=='*')
                    break;
                last[i] = str[i][j] + last[i];
            }
            string temp="";
            for(k=0;k<j;k++)
                temp+=str[i][k];
            str[i]=temp;
        }

        int flag = 0;
        t=0;
        for(i=0;i<110;i++)
        {
            st.clear();
            for(j=0;j<n;j++)
            {
                if(i<first[j].size())
                    st.insert(first[j][i]);
            }
            if(st.size()==1)
                for(auto it:st)
                    ans[t]=it;
            else if(st.size()>1)
            {
                flag = 1;
                break;
            }
            else
                break;
            t++;
        }
        t = 9999;
        for(i=0;i<110;i++)
        {
            st.clear();
            for(j=0;j<n;j++)
            {
                if(i<last[j].size())
                    st.insert(last[j][last[j].size()-i-1]);
            }
            if(st.size()==1)
                for(auto it:st)
                    ans[t]=it;
            else if(st.size()>1)
            {
                flag = 1;
                break;
            }
            else
                break;
            t--;
        }
        int start;
        for(i=0;i<10000;i++)
        {
            if(ans[i]=='*')
            {
                start = i;
                break;
            }
        }
        for(i=0;i<n;i++)
        {
            int sz = str[i].size();
            for(j=0;j<sz;j++)
            {
                if(str[i][j]!='*')
                {
                    ans[start]=str[i][j];
                    start++;
                }
            }
        }
        for(i=0;i<10000;i++)
            if(ans[i]=='*')
                ans[i]='A';

        if(flag)
            cout<<"Case #"<<ks<<": *"<<endl;
        else
            cout<<"Case #"<<ks<<": "<<ans<<endl;
        ks++;
    }

    return 0;
}
