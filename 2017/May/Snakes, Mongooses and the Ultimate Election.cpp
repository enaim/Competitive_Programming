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


    int tks,ks=1,i,cnt,cnt1,len;
    int tmp[110];
    char str[110];
    scanf("%d",&tks);
    while(tks--)
    {
        cnt = cnt1 =0;
        scanf("%s",str);
        len = strlen(str);
        for(i=0;i<110;i++)
            tmp[i] = 100;
        for(i=0;i<len;i++)
        {
            if(str[i] == 's')
            {
                tmp[i]=1;
                cnt1++;
            }
            else
                cnt++;
        }

        for(i=0;i<len;i++)
        {
            if(str[i] == 'm')
            {
                if(tmp[i-1]==1)
                {
                    tmp[i-1]=0;
                    cnt1--;
                }
                else if(tmp[i+1]==1)
                {
                    tmp[i+1]=0;
                    cnt1--;
                }
            }
        }

        if(cnt1>cnt)
            printf("snakes\n");
        else if(cnt1<cnt)
            printf("mongooses\n");
        else
            printf("tie\n");


//        printf("Case %d: ",ks++);
    }



    return 0;
}
