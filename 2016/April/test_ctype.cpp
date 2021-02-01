#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <iostream>
#include <algorithm>
using namespace std;

char c;
int a;

char s[112];

void _scan()
{
    scanf("%s",&s);
    scanf("%d",&a);
    printf("%c -> %d\n",c,a);
}

void _cin(){
    cin>>s>>a;
    cout<<s<<" -> "<<a<<endl;
}

int main()
{

//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    _cin();



    return 0;
}
