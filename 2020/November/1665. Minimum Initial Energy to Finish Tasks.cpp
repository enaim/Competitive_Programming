struct node{
    long long a,m;
};
node ar[100010];

bool compare(node x, node y)
{
    return abs(x.a-x.m)>abs(y.a-y.m);
}

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size(),i;
        long long left = 0, right = 2e18+1e5, mid;
        for(i=0;i<n;i++)
        {
            ar[i].a = tasks[i][0];
            ar[i].m = tasks[i][1];
            left+=ar[i].a;
        }
        sort(&ar[0],&ar[n],compare);
        while(left<=right)
        {
            mid = (left+right)/2;
            long long check = mid;
            for(i=0;i<n;i++)
            {
                if(check>=ar[i].m)
                    check-=ar[i].a;
                else
                    break;
            }
            if(i==n)
                right = mid - 1LL;
            else
                left = mid + 1LL;
        }
        return right + 1;
    }
};
