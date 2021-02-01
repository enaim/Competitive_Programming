#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    deque<int>dq;

    dq.push_front(10);
    dq.push_back(20);
    dq.push_front(30);
    dq.push_back(40);
    dq.pop_front();
    dq.pop_back();

    printf("Front -> %d\n",dq.front());
    printf("Back -> %d\n",dq.back());
    printf("Size - > %d\n",dq.size());
    printf("Is Empty -> %d\n",dq.empty());


    return 0;
}
