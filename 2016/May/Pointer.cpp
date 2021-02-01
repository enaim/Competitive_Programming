#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{

    int x = 10;
    double db = 10.23, *pdb;
    pdb = &db;
    *pdb = 3.14; //db = 3.14;

    deb(db);


    int *p;
    p = &x;

    printf("%X\n",p);

    int y = *p;
    deb(y);

    int ar[10];

    p = ar; //&ar[0] == ar;
    for(int i=0;i<10;i++)
    {
        *p = i*i;
        p++;
    }

    for(int i=0;i<10;i++)
        cout<<i<<" "<<ar[i]<<endl;

//    sort(&ar[0],&ar[n]);
//    sort(ar,ar+n);

    vector<string>v(10,"Maksud");

    v[3] = "ZZ";
    v[5] = "AA";

    sort(v.begin()+2 , v.begin()+8);


    int i=0;
    for(vector<string>::iterator it = v.begin();it!=v.end();it++,i++)
    {
        cout<<i<<" # "<<*it<<" == "<<v[i]<<endl;
    }


    return 0;
}
