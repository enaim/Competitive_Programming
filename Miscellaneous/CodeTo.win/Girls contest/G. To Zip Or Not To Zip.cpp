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



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,len,i,j;
    char str[110];
    int ar[110];
    scanf("%d",&tks);
    while(tks--)
    {
        memset(ar,0,sizeof ar);
        scanf("%s",str);
        len = strlen(str);

        for(i=0;i<len;i++)
        {
            ar[i]=1;
            for(j=i+1;j<len;j++)
            {
                if(str[i]==str[j])
                {
                    ar[i]++;
                }
                else
                    break;
            }
            i = i+ar[i]-1;
        }
        for(i=0;i<len;i++)
        {
            if(ar[i]>2)
            {
                printf("%d",ar[i]);
                i = i+ar[i]-1;
            }
            printf("%c",str[i]);
        }
        printf("\n");
    }

    return 0;
}
