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

set<int>st;
int ar[20],ks=1,cnt;
void go(int val,int k,int j)
{
    if(j== -1 && k==0 && val)
    {
        int x = sqrt(val);
        if(x*x==val || (x+1)*(x+1) == val )
        {
            st.insert(val);
        }
        return ;
    }
    if(j == -1)
        return;

    if(!(val == 0 && ar[j] == 0))
        go(val*10+ar[j],k,j-1);
    if(k>=1)
        go(val,k-1,j-1);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i,x;
    while(1==scanf("%d",&n))
    {
        st.clear();
        x = sqrt(n);
        if(x*x==n || (x+1)*(x+1) == n)
        {
            printf("0\n");
        }
        else
        {
            i = 0;
            while(n!=0)
            {
                ar[i] = n%10;
                n=n/10;
                i++;
            }
            cnt = i-1;
            for(i=1;i<=cnt;i++)
                go(0,i,cnt);
            for(set<int>::iterator it=st.begin();it!=st.end();it++)
            {
                x = *it;
            }
            i = 0;
            while(x!=0)
            {
                x/=10;
                i++;
            }
            if(st.size()==0)
                printf("-1\n");
            else
                cout<<cnt-i+1<<endl;
        }
    }

    return 0;
}
