class Solution {
public:
    int sumFourDivisors(vector<int>& ar) {
        int n = ar.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            int temp = ar[i];
            int sq = sqrt(temp)+1;
            int s = 0;
            int cnt = 0;
            for(int j=1;j<sq;j++)
            {
                if(temp%j==0)
                {
                    cnt++;
                    s+=j;
                    if((temp/j) != j)
                    {
                        s+=(temp/j);
                        cnt++;
                    }
                }
            }
            if(cnt==4)
                sum+=s;
        }
        return sum;
    }
};
