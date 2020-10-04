class Solution {
public:
    string longestPalindrome(string str) {
        int maxLength = 1;

    int start = 0;
    int len = str.size();

    int low, high;

    for (int i = 1; i < len; ++i)
    {
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    string ans="";
    for(int i=start;i<=start+maxLength-1;i++)
        ans+=str[i];

    return ans;
    }
};
