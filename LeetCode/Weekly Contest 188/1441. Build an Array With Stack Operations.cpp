class Solution {
public:
    vector<string> buildArray(vector<int>& ar, int m) {
        vector<string>vec;
        int n = ar.size();
        int ks = 0;
        int i = 1;
        while(ks<n && i<=m)
        {
            while(i<ar[ks])
                vec.push_back("Push"),vec.push_back("Pop"),i++;
            vec.push_back("Push");
            i++;
            ks++;
        }
        return vec;
    }
};
