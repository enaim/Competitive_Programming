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
    ll val;
    char str[20];
};

node ar[10010];
node br[20][10010];
ll sz[20];
ll discover[12];
ll cr[12];
ll len[10010];
char dr[12];
char value[12];
char tempVal[12];
ll inserted[12];
set<char>st[12],dig;

bool compare(node a, node b)
{
    return a.val<b.val;
}

ll digit(ll x)
{
    ll cnt = 0;
    while(x!=0LL)
    {
        x/=10LL;
        cnt++;
    }
    return cnt;
}

ll check(char c)
{
    ll i;
    for(i=0;i<10;i++)
        if(tempVal[i]==c)
            return i;
}

bool check1(char c)
{
    ll i;
    for(i=0;i<10;i++)
        if(value[i]==c)
            return true;
    return false;
}

ll convert(ll ind)
{
    ll v = 0LL,i;
    for(i=0;i<len[ind];i++)
        v = (v*10LL)+check(ar[ind].str[i]);
    return v;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll n = 10000;
        ll i,u,j,k,range;
        dig.clear();
        for(i=0;i<12;i++)
        {
            st[i].clear();
            tempVal[i]='t';
            value[i]='t';
            discover[i]=0LL;
            len[i]=0;
            sz[i]=0;
        }

        scanf("%lld",&u);
        for(i=0;i<n;i++)
            scanf("%lld%s",&ar[i].val,ar[i].str);

        sort(&ar[0],&ar[n],compare);

        for(i=0;i<n;i++)
        {
            len[i]=strlen(ar[i].str);
            if(digit(ar[i].val)==len[i])
            {
                br[len[i]][sz[len[i]]]=ar[i];
                sz[len[i]]++;
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<len[i];j++)
            {
                dig.insert(ar[i].str[j]);
                if(dig.size()==10)
                    break;
            }
            if(dig.size()==10)
                break;
        }
        if(ar[0].val==1)
        {
            discover[1]=1;
            value[1]=ar[0].str[0];
            for(ll z=0;z<10;z++)
                st[z].insert(value[1]);

        }

        stringstream ss;
        string temp;
        char ch;
        for(i=2;i<=u;i++)
        {
            for(j=0;j<sz[i];j++)
            {
                stringstream ss;
                temp.clear();
                node t = br[i][j];
                ss << t.val;
                temp =  ss.str();

                range = temp[0]-'0';
                if(discover[range]==1)
                    continue;

                ch = t.str[0];
                if(check1(ch))
                    continue;

                for(k=1;k<range;k++)
                {
                    if(discover[k]==0)
                        break;
                }
                if(k==range)
                {
                    discover[range]=1;
                    value[range]=ch;
//                    cout<<"dis i =  "<<range<<" "<<value[range]<<endl;
                    for(ll z=0;z<10;z++)
                        st[z].insert(ch);
                    continue;
                }
                ll cnt = 0;
                for(k=1;k<range;k++)
                {
                    ll szz = st[k].size();
                    if(discover[k]==1 || szz>=k)
                    {
                        continue;
                    }
                    st[k].insert(ch);
                    cnt++;
                }
                if(k==range)
                {
                    if(cnt==0)
                    {
                        discover[range]=1;
                        value[range]=ch;
//                        cout<<"dis i =  "<<range<<" "<<value[range]<<endl;
                        for(ll z=0;z<10;z++)
                            st[z].insert(ch);
                    }
                    else
                        st[range].insert(ch);
                }
            }
        }
        ll cnt = 0;
        for(i=0;i<10;i++)
        {
            if(discover[i]==1)
            {
                continue;
            }
            cr[cnt++]=i;
        }
        cnt = 0;
//        cout<<" "<<cnt<<endl;
        for(auto it:dig)
        {
            for(i=0;i<10;i++)
                if(it==value[i])
                    break;
            if(i==10)
                dr[cnt++]=it;
        }
//        cout<<" "<<cnt<<endl;
        for(i=0;i<10;i++)
            if(discover[i]==1)
                tempVal[i]=value[i];

//        for(i=0;i<10;i++)
//        {
//            if(discover[i]==1)
//                printf("%lld - > %c\n",i,value[i]);
//        }
        do{

            for(i=0;i<cnt;i++)
            {
                tempVal[cr[i]]=dr[i];
            }

            for(i=0;i<n;i++)
            {
                if(convert(i)<=ar[i].val)
                    continue;
            }
            if(i==n)
                break;
        }while(next_permutation(dr,dr+cnt));
//        for(i=0;i<10;i++)
//        {
//            if(discover[i]==1)
//                printf("%lld - > %c\n",i,value[i]);
//        }
        printf("Case #%d: ",ks++);
        for(i=0;i<10;i++)
            printf("%c",tempVal[i]);
        printf("\n");
    }

    return 0;
}
