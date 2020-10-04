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

//    char str1[110];
//    cin.getline(str1,110);
//    cout<<str1<<endl;
//
//    string st;
//    getline(cin,st);
//    cout<<st<<endl;

    string s;

    cin>>s;

    s += "#"+s;
    cout<<"S: "<<s<<endl;

    string b = s.substr(1,5);
    cout<<b<<endl;

    reverse(b.begin(),b.end());

    cout<<"Reversed: "<<b<<endl;
    cout<<b.size()<<endl;

    sort(b.begin(),b.end());
    cout<<"Sorted: "<<b<<endl;

    sort(b.rbegin(),b.rend());
    cout<<"Reversed Sorted: "<<b<<endl;

    sort(b.begin(),b.begin()+4);
    cout<<"Sorted by first 4 char:"<<b<<endl;


    cout<<s<<endl;

    char ar[22];
    scanf("%s",ar);
    s = ar;
    cout<<s<<"  Len: "<<s.size()<<endl;

    printf("C++STRING: %s\n",s.c_str());

    int index = s.find("34");
    cout<<"Find Index: "<<index<<endl;

    index = s.find("##");
    cout<<"Find Index: "<<index<<endl;

    return 0;
}
