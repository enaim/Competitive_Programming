#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tks,ks=1,i,j,n,l,r,mid;
    long long ar[1200],ans;
    int cnt = 0;
    set<long long>st;
    for(i=0;i<34;i++)
    {
        for(j=0;j<34;j++)
        {
            if(i==j)
                continue;
            st.insert(pow(2LL,i)+pow(2LL,j));
        }
    }
    for(auto it : st)
    {
        ar[cnt++] = it;
    }

    scanf("%d",&tks);
    while(tks--)
    {
        ans = 1000000000000000;
        scanf("%d",&n);
        for(i=0;i<561;i++)
        {
            ans = min(ans,abs(ar[i]-n));
            if(ar[i]>n)
                break;
        }
        cout<<ans<<endl;
    }

    return 0;
}
