class Solution {
public:
    void nextPermutation(vector<int>& vec) {
        int cnt = 0;
        int sz = vec.size();
        do{
            cnt++;
            if(cnt==2)
                break;
        }while(next_permutation(vec.begin(),vec.end()));
    }
};
