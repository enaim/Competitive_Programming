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

    char str[10][10];

    int cnt1=0,cnt2=0,i,j;
    for(i=0;i<8;i++)
        scanf("%s",str[i]);
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
        {
            if(str[i][j]=='q')
                cnt1+=9;
            else if(str[i][j] == 'r')
                cnt1+=5;
            else if(str[i][j] == 'b')
                cnt1+=3;
            else if(str[i][j] == 'n')
                cnt1+=3;
            else if(str[i][j] == 'p')
                cnt1+=1;
            else if(str[i][j] == 'Q')
                cnt2+=9;
            else if(str[i][j] == 'R')
                cnt2+=5;
            else if(str[i][j] == 'B')
                cnt2+=3;
            else if(str[i][j] == 'N')
                cnt2+=3;
            else if(str[i][j] == 'P')
                cnt2+=1;
        }
        if(cnt2 > cnt1)
            printf("White\n");
        else if(cnt2 < cnt1)
            printf("Black\n");
        else
            printf("Draw\n");


    return 0;
}
