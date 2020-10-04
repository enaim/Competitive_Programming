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

int ar[30];
int br[30];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    string str,x,y,z;
    int i,j,k,f;
    while(tks--)
    {
        for(i=0;i<26;i++)
            ar[i]=0;
        cin>>str;
        sort(str.begin(),str.end());

        int n = str.size();
        for(i=0;i<n;i++)
            ar[str[i]-'a']++;
        for(i=0;i<26;i++)
            br[i]=ar[i];

        z = "";
        f = 0;
        for(i=0;i<26;i++)
        {
            while(ar[i])
            {
                f = 1;
                char ch  =('a'+ i);
                z = z + ch;
                ar[i]--;
            }
            if(f)
                break;
        }
        f = 0;
        for(j = 26-1;j>i;j--)
        {
            if(f==0)
            while(ar[j])
            {
                f = 1;
                char ch  =('a'+ j);
                z = z + ch;
                ar[j]--;
            }

            if(f==1)
            while(ar[j])
            {
                f = 0;
                char ch  =('a'+ j);
                z = ch + z;
                ar[j]--;
            }
        }

        f = 0;
        for(i=1;i<z.size();i++)
            if(z[i-1]==z[i]-1 || z[i-1]-1==z[i])
            {
                f = 1;
                break;
            }

        if(f)
        {
            for(i=0;i<26;i++)
                ar[i]=br[i];
            z = "";
            f = 0;
            for(i=26-1;i>=0;i--)
            {
                while(ar[i])
                {
                    f = 1;
                    char ch  = ('a'+ i);
                    z = z + ch;
                    ar[i]--;
                }
                if(f)
                    break;
            }
            f = 0;
            for(j = 0;j<i;j++)
            {
                if(f==0)
                while(ar[j])
                {
                    f = 1;
                    char ch  =('a'+ j);
                    z = ch + z;
                    ar[j]--;
                }

                if(f==1)
                while(ar[j])
                {
                    f = 0;
                    char ch  =('a'+ j);
                    z = z + ch;
                    ar[j]--;
                }
            }

            f = 0;
            for(i=1;i<z.size();i++)
                if(z[i-1]==z[i]-1 || z[i-1]-1==z[i])
                {
                    f = 1;
                    break;
                }
        }

        if(f)
            printf("No answer\n");
        else
            cout<<z<<endl;
    }

    return 0;
}
