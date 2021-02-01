#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


#include <iostream>
#include <algorithm>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int x;
    long long l;
    double y;
    cin>>x>>l>>y;

    deb(abs(x));
    deb(abs(l));
    deb(abs(y));



    return 0;
}
