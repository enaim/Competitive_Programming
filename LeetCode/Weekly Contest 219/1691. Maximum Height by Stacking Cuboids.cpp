struct node{
    int x,y,z;
};
node ar[110];
int n;

bool compare(node a,node b)
{
    if(a.x==b.x)
    {
        if(a.y==b.y)
            return a.z>b.z;
        return a.y>b.y;
    }
    return a.x>b.x;
}

int dp[110][110];
int go(int last, int pos)
{
    if(pos==n+1)
        return 0;
    int &re = dp[last][pos];
    if(re!=-1)
        return re;
    re = 0;
    for(int i=pos+1;i<=n;i++)
    {
        if((ar[last].x>=ar[i].x && ar[last].y>=ar[i].y && ar[last].z>=ar[i].z) || last==0)
        {
            re = max(re,ar[i].x+go(i,i));
        }
        re = max(re,go(last,i));
    }
    return re;
}

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int sz = cuboids.size();
        int i;
        n = sz;
        for(int i=0;i<n;i++)
        {
            int a[3]={0};
            a[0]=cuboids[i][0];
            a[1]=cuboids[i][1];
            a[2]=cuboids[i][2];
            sort(&a[0],&a[3],greater<int>());
            ar[i+1].x = a[0];
            ar[i+1].y = a[1];
            ar[i+1].z = a[2];
        }
        sort(&ar[1],&ar[n+1],compare);
        memset(dp,-1,sizeof dp);
        return go(0,0);
    }
};
