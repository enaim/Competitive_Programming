class Solution {
public:
    int numberOfMatches(int n) {
        int cnt = 0;
        while(n>1)
        {
            if(n&1)
            {
                cnt+=((n-1)/2);
                n/=2;
                n++;
            }
            else
            {
                cnt+=(n/2);
                n/=2;
            }
        }
        return cnt;
    }
};
