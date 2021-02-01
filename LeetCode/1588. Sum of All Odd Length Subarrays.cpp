class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int i,j,k;
        long long sum=0;
        for(i=1;i<=n;i+=2)
        {
            for(j=0;j<n;j++)
            {
                for(k=j;k<=j+i-1 && j+i-1<n;k++)
                    sum += arr[k];
            }
        }
        return sum;
    }
};
