#include <bits/stdc++.h>

using namespace std;

long long BigMod (long long b,long long p,long long M)
{
    long long ans = 1;
    while(p)
    {
        if(p & 1)
            ans = (ans * b) % M;
        b = (b * b) % M;
        p = p >> 1;
    }

    return ans;
}

int dp[110][1010];
int nn,res,p;

int go(int ind,int sum)
{
    if(sum==res)
        return 1;
    if(ind>nn || sum>res)
        return 0;
    int &re = dp[ind][sum];
    if(re!=-1)
        return re;
    re = 0;
    int z = BigMod(ind,p,1e9+7);
    re+=go(ind+1,sum+z);
    re+=go(ind+1,sum);
    return re;
}

// Complete the powerSum function below.
int powerSum(int X, int N) {
    res = X;
    memset(dp,-1,sizeof dp);
    nn = sqrt(X);
    p = N;
    return go(1,0);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}
