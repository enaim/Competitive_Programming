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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

char str1[110],st[110];
char pq[210];
int n,Prefix,x;

struct node{
    char str[110];
    int len;
    int ind;
};

node ar[210];

bool compare(node a,node b)
{
    return a.len>b.len;
}

void func()
{
    int i,j,k,cnt,len1,f;
    st[0]='\0';
    if(Prefix==1)
    {
        pq[ar[0].ind]='S';
        pq[ar[1].ind]='P';

        strcpy(st,ar[0].str);
        for(i=n-1;i>0;i--)
            st[i]=st[i-1];
        st[0]=ar[1].str[0];
        st[n]='\0';

    }
    else
    {
        pq[ar[0].ind]='P';
        pq[ar[1].ind]='S';
        strcpy(st,ar[0].str);
        st[n-1]=ar[1].str[n-2];
        st[n]='\0';
    }

    len1 = n-1;
    for(i=2;i<x;i+=2)
    {
        strcpy(str1,ar[i].str);
        len1--;
        f =0;
        if(str1[0]==st[0])
        {
            k = cnt = 0;
            while(st[k]==str1[k] && k<len1)
                k++;
            if(k==len1)
                f = 1;
        }
        if(f)
        {
            pq[ar[i].ind]='P';
            pq[ar[i+1].ind]='S';
        }
        else
        {
            pq[ar[i].ind]='S';
            pq[ar[i+1].ind]='P';
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,k,l,cnt,len1,f,t,p,s,mx;

    while(1==scanf("%d",&n))
    {
        x = (n-1)*2;
        for(i=0;i<x;i++)
        {
            scanf("%s",ar[i].str);
            ar[i].ind = i;
            ar[i].len = strlen(ar[i].str);
        }

        sort(&ar[0],&ar[x],compare);

        for(i=1;i<n-1;i++)
        {
            if(ar[0].str[i]==ar[1].str[i-1])
                continue;
            else break;
        }
        Prefix = 0;
        if(i==n-1)
        {
            Prefix = 1;
            pq[ar[0].ind]='P';
            pq[ar[1].ind]='S';
            strcpy(st,ar[0].str);
            st[n-1]=ar[1].str[n-2];
            st[n]='\0';
        }
        else
        {
            pq[ar[0].ind]='S';
            pq[ar[1].ind]='P';

            strcpy(st,ar[0].str);
            for(i=n-1;i>0;i--)
                st[i]=st[i-1];
            st[0]=ar[1].str[0];
            st[n]='\0';
        }
        len1 = n-1;
        for(i=2;i<x;i+=2)
        {
            strcpy(str1,ar[i].str);
            len1--;
            f = t = 0;
            if(str1[0]==st[0])
            {
                k = cnt = 0;
                while(st[k]==str1[k] && k<len1)
                    k++;
                if(k==len1)
                    f = 1;
            }
            if(f==1)
            {
                strcpy(str1,ar[i+1].str);
                if(str1[len1-1]==st[n-1])
                {
                    j = n-1;
                    k = len1-1;
                    cnt = 0;
                    while(st[j]==str1[k] && k>=0)
                        k--,j--,cnt++;
                    if(cnt==len1)
                        t = 1;
                }
            }
            if(str1[len1-1]==st[n-1] && !f)
            {
                j = n-1;
                k = len1-1;
                cnt = 0;
                while(st[j]==str1[k] && k>=0)
                    k--,j--,cnt++;
                if(cnt==len1)
                    t = 2;
            }
            if(t==2)
            {
                strcpy(str1,ar[i+1].str);
                if(str1[0]==st[0])
                {
                    k = cnt = 0;
                    while(st[k]==str1[k] && k<len1)
                        k++;
                    if(k==len1)
                        f = 2;
                }
            }
            if(f==1 && t==1)
            {
                pq[ar[i].ind]='P';
                pq[ar[i+1].ind]='S';
            }
            else if(f==2 && t==2)
            {
                pq[ar[i].ind]='S';
                pq[ar[i+1].ind]='P';
            }
            else
            {
                func();
                break;
            }
        }
        pq[x]='\0';
        printf("%s\n",pq);
    }

    return 0;
}
