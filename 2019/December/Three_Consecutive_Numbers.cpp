#include<bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int n;
    scanf("%d",&n);
    if(n%3==0)
        printf("%d %d %d\n",(n/3)-1,n/3,(n/3)+1);
    else
        printf("-1\n");

    return 0;
}
