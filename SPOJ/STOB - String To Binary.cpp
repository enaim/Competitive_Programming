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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[1010];
    char c[25];
    long long sum,i,j,rev,a,n;
    int tks,ks=1;
    scanf("%d",&tks);
    map<char,int>mp;
    while(tks--)
    {
        mp.clear();
        scanf("%s",str);

        n = 0;
        for(i=0;i<strlen(str);i++)
        {
            mp[str[i]]++;
            if(mp[str[i]] == 1)
                n+= str[i];
        }

        i=0;
        while(n != 0)
        {
            a=n%2;
            n=n/2;
            c[i]=a;
            i++;
        }

        rev = 0;
        for(j=i-1;j>=0;j--)
        {
            rev = rev*10 + c[j];
        }
        if(tks!=0)
            printf("#%d : %lld\n\n",ks++,rev);
        else
            printf("#%d : %lld\n",ks++,rev);

    }

    return 0;
}
