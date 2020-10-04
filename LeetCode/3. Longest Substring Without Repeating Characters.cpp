class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int ar[256]={0};
        int n = str.size();
        int i,last = 0,first = 0,ans=0;
        for(i=0;i<n;i++)
        {
            int ch = str[i];
            if(ar[ch]==0)
                ar[ch]=1;
            else
            {
                while(last<=first)
                {
                    ar[str[last]]=0;
                    last++;
                    if(ar[ch]==0)
                        break;
                }
                ar[ch]=1;
            }
            first = i;
            ans = max(ans,first-last+1);
        }
        return ans;
    }
};
