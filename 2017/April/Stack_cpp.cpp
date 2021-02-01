#include <stdio.h>
#include <string.h>
#include <math.h>

#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    stack<int>stck;
    int i,top;
    for(i=0;i<5;i++)
        stck.push(i);
    printf("size -> %d\n",stck.size());

    top = stck.top();
    stck.pop();
    printf("Top -> %d\n",top);
    printf("size -> %d\n",stck.size());
    printf("Is this empty(1) or not(0) -> %d\n",stck.empty());

    return 0;
}
