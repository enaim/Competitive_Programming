class Solution {
    int DS(int n)
    {
        int sum = 0;
        while(n!=0)
        {
            int rem = n%10;
            n/=10;
            sum+=(rem*rem);
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        map<int,int>mp;
        while(true)
        {
            int sum = DS(n);
            if(sum==1)
                return true;
            mp[sum]++;
            if(mp[sum]>1)
                return false;
            n = sum;
        }

    }
};
