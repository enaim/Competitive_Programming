#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'maxHeight' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY tablePositions
 *  2. INTEGER_ARRAY tableHeights
 */

int maxHeight(vector<int> position, vector<int> height) {
    int n = position.size();
    int ans = 0;
    for(int i=1;i<n;i++)
    {
        int dis = position[i]-position[i-1]-1;
        if(dis==0)
            continue;
        int mx = max(height[i],height[i-1]);
        int mn = min(height[i],height[i-1]);
        if(mn+dis<=mx+1)
            ans = max(ans,mn+dis);
        if(dis>=mx-mn)
            ans = max(ans,mx+((dis-(mx-mn)+1)/2));
    }
    return ans;
}

int main()
