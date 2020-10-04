class Solution {
public:
    int numTeams(vector<int>& vec) {
        int cnt = 0;
        int n = vec.size();
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++)
                    if((vec[i]<vec[j] && vec[j]<vec[k]) || (vec[i]>vec[j] && vec[j]>vec[k]))
                        cnt++;
        return cnt;
    }
};
