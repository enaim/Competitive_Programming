typedef long long ll;

class Solution {
public:
    int concatenatedBinary(int N) {
        ll mod = 1e9+7, i, x, rem, n=N, val = 1, ans = 0LL;
        for(i=n;i>=1;i--)
        {
            x = i;
            while(x!=0)
            {
                rem = x%2;
                ans = (ans+(rem*val))%mod;
                x/=2;
                val=(val*2)%mod;
            }
        }
        return ans;
    }
};
