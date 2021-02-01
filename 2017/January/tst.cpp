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
#include <sstream>

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

    char input[] = "PI 3.1416 Maksud 23.23";
    string inp = input;

    printf("%s\n",inp.c_str());

    stringstream ss;
    ss<<inp;
    string tmp;
    double val;

    while(ss>>tmp>>val)
    {
        deb(tmp);
        deb(val);
    }

    return 0;
}
