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

    char str[30];
    long long r,s,rem,ans,i;

    while(1==scanf("%s",str))
    {
        long long len = strlen(str);
        r=0;
        for(i=0;i<len-1;i++)
        {
            r = r*10 + str[i]-'0';
        }
        s = str[len-1];
        ans = 0;

        rem = (r-1) / 4;
        ans = rem*12;

        if(r%2==0)
            ans+=6;

        if(r%4==1 || r%4==2)
            ans+=(r-1);
        else if(r%4==3 || r%4 == 0)
            ans+=(r-3);

        if(s =='a')
            ans+=4;
        else if(s =='b')
            ans+=5;
        else if(s =='c')
            ans+=6;
        else if(s =='d')
            ans+=3;
        else if(s =='e')
            ans+=2;
        else
            ans+=1;

        printf("%I64d\n",ans);
    }

    return 0;
}
