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

int ar[125][7];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,i,cnt,x;
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=1;i<=122;i++)
            for(j=0;j<7;j++)
                ar[i][j]-1;

        for(i=0;i<6;i++)
            sz[i]=0;
        cnt = 0;
        for(i=1;i<=595;i+=5)
        {
            cnt++;
            printf("%d\n",i);
            fflush(stdout);
            scanf("%s",str);
            x = str[0]-'A';
            sz[x]++;
            ar[cnt][1]=x;
        }
        for(i=0;i<5;i++)
            if(sz[i]!=24)
                ans[1]=x;


        for(i=0;i<6;i++)
            sz[i]=0;
        cnt = 0;
        for(i=2;i<=595;i+=5)
        {
            cnt++;
            printf("%d\n",i);
            fflush(stdout);
            scanf("%s",str);
            x = str[0]-'A';
            sz[x]++;
            ar[cnt][2]=x;
        }

        for(i=0;i<5;i++)
            if(sz[i]!=24)
                ans[2]=x;


        for(i=0;i<6;i++)
            sz[i]=0;
        cnt = 0;
        for(i=3;i<=595;i+=5)
        {
            cnt++;
            printf("%d\n",i);
            fflush(stdout);
            scanf("%s",str);
            x = str[0]-'A';
            sz[x]++;
            ar[cnt][3]=x;
        }

        for(i=0;i<5;i++)
            if(sz[i]!=24)
                ans[3]=x;
        sum = ar[1]+ar[2]+ar[3];

        for(i=0;i<;i++)
            sz[i]=0;
        cnt = 0;
        z = 1;
        if(ans)
        for(i=4;i<=595;i+=5)
        {
            cnt++;
            if(ar[cnt][1]+ar[cnt][2]+ar[cnt][3]==sum && flag1 == 1)
            {
                temp1 = cnt;
                flag1 = 0;
                continue;
            }
            printf("%d\n",i);
            fflush(stdout);
            scanf("%s",str);
            x = str[0]-'A';
            sz[x]++;
            ar[cnt][3]=x;
        }

        int f = 1;
        for(i=0;i<5;i++)
            if(sz[i]!=24)
            {
                if(f==1)
                    a = i;
                else
                    b = i;
            }
        for(i=0;i<5;i++)
            sz[i]=0;
        for(i=1;i<=3;i++)
            sz[ar[cnt][i]]++;
        for(i=1;i<=3;i++)
            sz[ans[i]]++;
        f2 = 0;
        for(i=0;i<5;i++)
        {
            if(sz[i]!=2)
            {
                if(f2==0)
                {
                    f2 = 1;
                    t1 = i;
                }
                else
                    t2 = i;
            }
        }
            if(a==t1)
                ans[4]=t1;
            else
                ans[4]=t2;
    }

    return 0;
}
