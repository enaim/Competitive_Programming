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

    int tks,ks=1,d,s,len,sum,temp,i,cnt,x,mov,j;
    char str[100];
    int ar[50];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&d);
        scanf("%s",str);
        len = strlen(str);
        cnt = 0;
        s = 0;
        sum = 0;
        x = 1;
        for(i=0;i<len;i++)
        {
            if(str[i]=='C')
            {
                ar[++cnt] = i;
                x = x+x;
            }
            else
            {
                s++;
                sum+=x;
            }
        }
        if(d<s)
        {
            printf("Case #%d: IMPOSSIBLE\n",ks++);
            continue;
        }
        mov = 0;
        if(sum>d)
        {
            for(i=cnt;i>0;i--)
            {
                temp = 0;
                x = ar[i];
                for(j=x+1;j<len;j++)
                {
                    if(str[j]=='S')
                    {
                        swap(str[j-1],str[j]);
                        sum -= ( pow(2,i)- pow(2,i-1));
                        mov++;
                        if(sum<=d)
                        {
                            temp = 1;
                            break;
                        }
                    }
                    else
                        break;
                }
                if(temp)
                    break;
            }
        }
        printf("Case #%d: %d\n",ks++,mov);
    }

    return 0;
}
