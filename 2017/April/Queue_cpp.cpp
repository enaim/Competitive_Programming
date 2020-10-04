#include <stdio.h>
#include <string.h>
#include <math.h>

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    queue<int>Q;
    int i,top;
    for(i=0;i<5;i++)
        Q.push(i);
    printf("size -> %d\n",Q.size());

    top = Q.front();
    printf("Front - > %d\n",top);
    printf("Front - > %d\n",Q.front());
    Q.pop();
    printf("Top -> %d\n",top);
    printf("size -> %d\n",Q.size());
    printf("Is this empty(1) or not(0) -> %d\n",Q.empty());

    return 0;
}
