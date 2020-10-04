#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <iostream>
#include <algorithm>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

typedef long long ll;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int NumberOfSetBits(ll mask)
{
    int cnt = 0;
    for(int i=0;i<62;i++)
        if(mask & (1LL<<i))
            cnt++;
    return cnt;
}


int main()
{

    ll val;

    while(cin>>val)
        deb(NumberOfSetBits(val));

    int x = 1 <<3;
    int y  = 7>>2;

    int AND = (5&3);
    int OR = (5|3);
    int XOR = (5^3);


    deb(AND);
    deb(OR);
    deb(XOR);


    while(cin>>x)
    {
        if(x&1)
            puts("Odd");
        else puts("Even");
    }


    return 0;
}
