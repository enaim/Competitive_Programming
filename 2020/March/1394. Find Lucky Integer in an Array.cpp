class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int i,n = arr.size();
        int cnt = 0;
        cnt = 1;
        for(i=n-2;i>=0;i--)
        {
            if(arr[i]==arr[i+1])
                cnt++;
            else
            {
                if(cnt==arr[i+1])
                    return arr[i+1];
                cnt = 1;
            }
        }
        if(cnt==arr[i+1])
            return arr[i+1];
        return -1;
    }
};
