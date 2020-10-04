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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,k,i,j,s,e,len,f,l,m,z,len1,len2;
    char str[25],str1[25],str2[25];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%s",&f,str);
        len = strlen(str);
        strcpy(str1,str);
        ll cnt = 0;
        for(i=1;i<=len;i++)
        {
            for(j=0;j<len-i+1;j++)
            {
                for(k=0;k<i;k++)
                    str1[k]=str[j+k];
                str1[j+k] = '\0';
                len1 = strlen(str1);
                z = 0;
                for(k=1;k<=len1;k++)
                {
                    for(l=0;l<len1-k+1;l++)
                    {
                        for(m=0;m<k;m++)
                            str2[m]=str1[m+l];
                        str2[m+l] = '\0';
                        len2 = strlen(str2);

                        s = 0;
                        e = len2-1;

                        while(s<=e)
                        {
                            if(str2[s] != str2[e])
                                break;
                            s++;
                            e--;
                        }
                        if(s>e && k>=f)
                            z = 1;

                    }
                }
                if(z==0)
                    cnt++;
            }
        }

        printf("%lld\n",cnt);
    }

    return 0;
}
