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


    int tks,ks=1,i,len,cnt;
    char str[110];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",str);
        len = strlen(str);
        cnt = 0;
        for(i=0;i<len;i++)
            if(str[i]>='A' && str[i]<='Z' )
            cnt++;

        printf("%d\n",cnt);
    }

    return 0;
}
