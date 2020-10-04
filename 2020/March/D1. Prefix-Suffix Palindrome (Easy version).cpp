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

char str[5010];
string ans1,ans2,temp;

bool isPalindrome(string r)
{
    string p = r;
    reverse(p.begin(), p.end());
    return (r == p);
}

bool CheckStr(string s)
{
    int l = s.length();
    int i;
    for (i = l; i >0 ; i--) {
        if (isPalindrome(s.substr(0, i)))
        {
            ans1 = s.substr(0, i);
            break;
        }
    }
    for (i = 0; i < l; i++) {
        if (isPalindrome(s.substr(i, l)))
        {
            ans2 = s.substr(i, l);
            break;
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",str);
        int n = strlen(str);
        int cnt = 0,i,j;
        for(i=0;i<n/2;i++)
        {
            if(str[i]==str[n-i-1])
            {
                cnt++;
                continue;
            }
            break;
        }
        if(n==1)
        {
            printf("%c\n",str[0]);
            continue;
        }
        if(i==n/2)
        {
            printf("%s\n",str);
            continue;
        }

        temp.clear();
        for(i=cnt;i<n-cnt;i++)
            temp+=str[i];

        ans1.clear();
        ans2.clear();
        CheckStr(temp);

        for(i=0;i<cnt;i++)
            printf("%c",str[i]);
        if(ans1.size()>ans2.size())
            cout<<ans1;
        else
            cout<<ans2;
        for(i=n-cnt;i<n;i++)
            printf("%c",str[i]);
        printf("\n");
    }

    return 0;
}
