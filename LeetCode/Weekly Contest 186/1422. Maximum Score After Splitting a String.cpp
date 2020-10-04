class Solution {
public:
    int maxScore(string s) {
        int n = s.size(),i;
        int zero[n];
        int one[n];
        for(i=0;i<n;i++)
            zero[i]=one[i]=0;
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                if(s[i]=='0')
                    zero[0]++;
                else
                    one[0]++;
                continue;
            }
            if(s[i]=='0')
                zero[i]++;
            else
                one[i]++;
            zero[i]+=zero[i-1];
            one[i]+=one[i-1];
        }
        int mx = 0;
        for(i=0;i<n-1;i++)
            mx = max(zero[i]+one[n-1]-one[i],mx);
        return mx;
    }
};
