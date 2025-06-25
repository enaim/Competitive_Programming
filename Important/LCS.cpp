#include<bits/stdc++.h>
using namespace std;


int n,m;
string str1,str2;
int dp[110][110];
int lcsRecursive(int x, int y)
{
    if(x==0 || y==0)
        return 0;

    int &re = dp[x][y];
    if(re!=-1)
        return re;

    if(str1[x-1]==str2[y-1])
        return re = 1 + lcsRecursive(x-1,y-1);
    else
        return re = max( lcsRecursive(x-1,y), lcsRecursive(x,y-1) );
}

int lcsIterative()
{
    int lcs[110][110];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                lcs[i][j] = 0;
            else if(str1[i-1]==str2[j-1])
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else
                lcs[i][j] = max( lcs[i-1][j], lcs[i][j-1] );
        }
    }
    return lcs[n][m];
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    while(cin>>str1>>str2)
    {
        memset(dp,-1,sizeof dp);
        n = str1.size();
        m = str2.size();

        cout<<lcsRecursive(n, m)<<endl;
        cout<<lcsIterative()<<endl;
    }

    return 0;
}
