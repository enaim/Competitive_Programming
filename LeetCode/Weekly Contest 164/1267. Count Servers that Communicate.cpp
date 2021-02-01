class Solution {
public:
    int countServers(vector<vector<int>>& ar) {
        int i,j;
        int r[300];
        int c[300];
        int row = ar.size();
        int column = ar[i].size();
        for(i=0;i<row;i++)
        {
            int cnt = 0;
            for(j=0;j<column;j++)
            {
                if(ar[i][j]==1)
                    cnt++;
            }
            r[i]=cnt;
        }
        for(j=0;j<column;j++)
        {
            int cnt = 0;
            for(i=0;i<row;i++)
            {
                if(ar[i][j]==1)
                    cnt++;
            }
            c[j]=cnt;
        }
        int ans = 0;
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                if(ar[i][j]==1)
                {
                    if(r[i]>=2 || c[j]>=2)
                        ans++;
                }
            }
        }
        return ans;
    }
};
