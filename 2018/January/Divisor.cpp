#include<bits/stdc++.h>
using namespace std;


vector<int>divisor[1000010];

void Divisor()
{
    for(int i=1;i<=1000000;i++)
        for(int j=i;j<=1000000;j+=i)
            divisor[j].push_back(i);
}

int main()
{
    Divisor();
    int n;
    while(scanf("%d",&n)==1)
    {
        int sz = divisor[n].size();
        for(int i=0;i<sz;i++)
            printf("%d ",divisor[n][i]);
        printf("\n");
    }
    return 0;
}
