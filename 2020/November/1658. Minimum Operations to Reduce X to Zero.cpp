class Solution {
public:
    int minOperations(vector<int>& ar, int x) {
        int i, j, n = ar.size(), mn = 100000000;
        vector<int>cur(n+5);
        cur.clear();
        int sum = 0;

        if(ar[0]==x || ar[n-1]==x)
            return 1;

        if(ar[0]>x)
        {
            for(j=n-1;j>=0;j--)
            {
                sum+=ar[j];
                if(sum==x)
                    return (n-j);
            }
            return -1;
        }

        if(ar[n-1]>x)
        {
            for(j=0;j<n;j++)
            {
                sum+=ar[j];
                if(sum==x)
                    return j+1;
            }
            return -1;
        }

        sum = 0;
        for(j=n-1;j>=0;j--)
        {
            sum+=ar[j];
            if(sum==x)
                mn = min(mn,n-j);
        }

        sum = 0;
        for(j=0;j<n;j++)
        {
            sum+=ar[j];
            if(sum==x)
                mn = min(mn,j+1);
        }

        cur[0] = ar[0];
        for(i=1;i<n;i++)
            cur[i] = cur[i-1] + ar[i];

        sum = 0;
        for(i=0;i<n-1;i++)
        {
            sum += ar[i];
            if(sum>=x)
                break;

            int left = i+1;
            int right = n-1;
            int val = cur[n-1] - (x - sum);

            while(left<=right)
            {
                int mid = (left+right)/2;
                if(cur[mid]==val)
                {
                    mn = min(mn, i+ 1 + (n-1-mid));
                    break;
                }
                if(cur[mid]<val)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

        }
        if(mn==100000000)
            return -1;
        return mn;
    }
};
