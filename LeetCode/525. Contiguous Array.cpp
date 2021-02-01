/*
    1110000111
    101
    10
    10101010
*/
map<int,int>mp;
int ar[50010];
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        mp.clear();
        for(int i=0;i<nums.size();i++)
            if(nums[i]==0)
                nums[i] = -1;
        ar[0]=nums[0];
        int mx = -1;
        mp[ar[0]]=0;
        for(int i=1;i<nums.size();i++)
        {
            ar[i] = ar[i-1]+nums[i];
            if(ar[i]==0)
            {
                mx = max(mx,i+1);
                continue;
            }
            if(mp.find(ar[i])!=mp.end())
                mx = max(mx,i-mp[ar[i]]);
            else
                mp[ar[i]]=i;
        }
        return max(mx,0);
    }
};
