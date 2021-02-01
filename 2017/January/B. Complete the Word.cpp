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

    map<char,int>mp;
    char str[50010];
    int length,i,j,cnt,temp;
    bool x;

    while(1==scanf("%s",str))
    {
        length  = strlen(str);
        x = false;
        for(i=0;i<length-25;i++)
        {
            mp.clear();
            cnt = 0;
            for(j=i;j<=i+25;j++)
            {
                if(str[j] == '?')
                    cnt++;
                else if(mp[str[j]] == 0)
                    mp[str[j]]++;

            }
            if((mp.size() + cnt) == 26)
            {
                x = true;
                temp = i;
                break;
            }
        }
        if(x)
        {
            char ch = 'A';
            for(int i=0;i<length;i++)
            {
                if( str[i] == '?' && ch<='A'+ 25 && ch<='Z' && temp <= i)
                {
                    while(mp[ch]!=0 && ch<='Z'-1)
                        ch++;

                    printf("%c",ch++);
                }
                else if(str[i] == '?')
                    printf("A");
                else
                    printf("%c",str[i]);
            }
            printf("\n");
        }
        else
            printf("-1\n");
    }

    return 0;
}
