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

    char str[110];
    char temp[210];

    while(1==scanf("%s",str))
    {
        int len = strlen(str);
        int cnt = 0;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='A' ||str[i]=='E' ||str[i]=='I' ||str[i]=='O' ||str[i]=='U' ||str[i]=='Y'
            ||str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u' ||str[i]=='y')
                continue;
            temp[cnt++]='.';
            if(str[i]<='Z')
                temp[cnt++] = str[i] + 32;
            else
                temp[cnt++] = str[i];
        }
        temp[cnt] = '\0';

        printf("%s\n",temp);
    }

    return 0;
}
