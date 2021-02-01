class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& vec) {
        int sz = vec.size();
        int sum = 0;
        for(int i=1;i<sz;i++)
        {
            sum += max(abs(vec[i-1][0]-vec[i][0]),abs(vec[i-1][1]-vec[i][1]));
        }
        return sum;
    }
};
