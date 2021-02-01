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

int i,j;
char str[300010];
vector<int>odd,even;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        odd.clear();
        even.clear();
        scanf("%s",str);
        int n = strlen(str);
        for(i=0;i<n;i++)
        {
            int x = str[i]-'0';
            if(x%2==0)
                even.pb(x);
            else
                odd.pb(x);
        }
        int sz1 = even.size();
        int sz2 = odd.size();
        i = j = 0;
        while(i<sz1 && j<sz2)
        {
            if(even[i]<odd[j])
            {
                printf("%d",even[i]);
                i++;
            }
            else
            {
                printf("%d",odd[j]);
                j++;
            }
        }
        while(i<sz1)
        {
            printf("%d",even[i]);
            i++;
        }
        while(j<sz2)
        {
            printf("%d",odd[j]);
            j++;
        }
        printf("\n");
    }

    return 0;
}
