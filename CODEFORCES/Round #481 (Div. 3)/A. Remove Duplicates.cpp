#include<bits/stdc++.h>
using namespace std;


int main()
{
    int i,j,n,ar[1010];
    scanf("%d",&n);
    int x = 1;
    int cnt = 0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=i-1;j>=0;j--)
        {
            if(ar[i]==ar[j])
                ar[j]=0;
        }
        if(ar[i])
            cnt++;
    }
    cout<<cnt<<endl;
    for(i=0;i<n;i++)
    {
        if(x && ar[i])
        {
            cout<<ar[i];
            x=0;
        }
        else if(ar[i])
            cout<<" "<<ar[i];
    }
    cout<<endl;

    return 0;
}
