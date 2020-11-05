class Solution {
public:
    int countBinarySubstrings(string str) {
        int n = str.size();
        vector<int>vec;
        int cnt = 1,i;
        for(i=1;i<n;i++)
        {
          if(str[i]==str[i-1])
          {
            cnt++;
          }
          else
          {
            vec.push_back(cnt);
            cnt = 1;
          }
        }
        vec.push_back(cnt);
        int sz  = vec.size();
        int ans = 0;
        for(i=1;i<sz;i++)
          ans+=min(vec[i],vec[i-1]);
        return ans;
    }
};
