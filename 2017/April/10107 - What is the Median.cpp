#include<bits/stdc++.h>
using namespace std;


int main()
{

//    freopen("in.txt","r",stdin);

    long long mid,i=1,ar[10010];
    while(scanf("%d",&ar[i])==1)
    {
        if(i==1)
            mid = ar[i];
        else if(i%2!=0)
        {
            sort(&ar[1],&ar[i+1]);
            mid = ar[(i/2)+1];
        }
        else
        {
            sort(&ar[1],&ar[i+1]);
            mid= (ar[i/2] + ar[(i/2)+1])/2;
        }
        printf("%lld\n",mid);
        i++;
    }

    return 0;
}
