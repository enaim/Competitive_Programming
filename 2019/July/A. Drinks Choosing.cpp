#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)==2)
    {
        int cnt=0,rem,x;
        set<int>st;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            st.insert(x);
            mp[x]++;
        }
        cnt = 0;
        for(auto it:st)
            cnt+=(mp[it]/2);
        rem = max(0,((n+1)/2) - cnt);
        cout<<cnt*2+rem<<endl;
    }

    return 0;
}
