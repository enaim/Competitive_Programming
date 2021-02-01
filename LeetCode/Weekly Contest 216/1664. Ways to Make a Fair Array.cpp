int odd[100010];
int even[100010];
int rodd[100010];
int reven[100010];
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int i,sumo,sume;
        odd[0]=even[0]=0;
        for(i=1;i<=n;i++)
        {
            if(i&1)
                odd[i] = odd[i-1]+nums[i-1], even[i] = even[i-1];
            else
                even[i] = even[i-1]+nums[i-1], odd[i] = odd[i-1];
        }
        rodd[n+1]=reven[n+1]=0;
        for(i=n;i>=1;i--)
        {
            if(i&1)
                rodd[i] = rodd[i+1]+nums[i-1], reven[i] = reven[i+1];
            else
                reven[i] = reven[i+1]+nums[i-1], rodd[i] = rodd[i+1];
        }
        int cnt = 0;
        for(i=1;i<=n;i++)
        {
            sumo = odd[i-1] + reven[i+1];
            sume = even[i-1] + rodd[i+1];
            if(sumo == sume)
                cnt++;
        }
        return cnt;
    }
};
