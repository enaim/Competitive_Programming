#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    long long x,y;
    int tks,ks=1;

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",(long long)(sqrt(x)*sqrt(y)));
    }
    return 0;
}
