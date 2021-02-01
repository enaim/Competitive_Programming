#include<bits/stdc++.h>
using namespace std;

#define pb push_back

int main()
{
    long long i,n,cnt,m=1e9+7;
    char str[100010];
    vector<long long>vec;
    while(scanf("%s",str)==1)
    {
        vec.clear();
        n = strlen(str);
        cnt = 0;
        for(i=0;i<n;i++)
        {
            if(str[i]=='b')
                vec.pb(cnt),cnt = 0;
            else if(str[i]=='a')
                cnt++;
        }
        if(cnt)
            vec.pb(cnt);
        long long ans = 1;
        long long sz = vec.size();
        for(i=0;i<sz;i++)
        {
            ans = (ans%m)*(vec[i]+1);
            ans = ans%m;
        }
        cout<<ans-1<<endl;
    }

    return 0;
}
