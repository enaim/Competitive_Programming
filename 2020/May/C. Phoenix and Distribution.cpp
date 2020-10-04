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

char str[100010];
int ar[30];
set<char>st;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        st.clear();
        memset(ar,0,sizeof ar);
        int i,j,n,k,f,start,t;

        scanf("%d%d",&n,&k);
        scanf("%s",str);
        sort(&str[0],&str[n]);

        for(i=0;i<n;i++)
        {
            ar[str[i]-'a']++;
            st.insert(str[i]);
        }

        for(i=0;i<26;i++)
        {
            if(ar[i])
                break;
        }

        start = i;
        if(ar[start]<k)
        {
            printf("%c\n",str[k-1]);
            continue;
        }

        f = 0;
        for(i=0;i<26;i++)
            if(ar[i]%k!=0)
            {
                f = 1;
                break;
            }

        if(f==1)
        {
            if(st.size()==1)
            {
                t = (n+k-1)/k;
                while(t--)
                    for(auto it:st)
                        printf("%c",it);
                printf("\n");
                continue;
            }
            if(st.size()==2 && ar[start]==k)
            {
                for(i=0;i<n;i+=k)
                    printf("%c",str[i]);
                printf("\n");
                continue;
            }
            printf("%c",str[0]);
            for(i=k;i<n;i++)
                printf("%c",str[i]);
            printf("\n");
            continue;
        }
        if(st.size()>=3 || (st.size()==2 && ar[start]>k))
        {
            printf("%c",str[0]);
            for(i=k;i<n;i++)
                printf("%c",str[i]);
            printf("\n");
            continue;
        }


        for(i=0;i<26;i++)
        {
            t = ar[i]/k;
            for(j=0;j<t;j++)
                printf("%c",'a'+i);
        }
        printf("\n");
    }

    return 0;
}
