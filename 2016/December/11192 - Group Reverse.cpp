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
    char str1[110];
    int n;

    while(gets(str))
    {
        n = str[0]-'0';
        if(n==0)
            break;

        int len = strlen(str);
        int div = (len-2) / n;

        int j = 0;
        for(int i=2;i<len;i++)
        {
            str1[j++] = str[i];
            if(j==div)
            {
                for(int k = div-1;k>=0;k--)
                    printf("%c",str1[k]);
                j = 0;
            }
        }

        printf("\n");
    }

    return 0;
}
