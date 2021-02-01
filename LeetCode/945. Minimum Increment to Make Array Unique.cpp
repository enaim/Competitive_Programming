#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());
        int cnt = 0;
        for(int i=1;i<A.size();i++)
        {
            if(A[i-1]>=A[i])
            {
                cnt+=abs(A[i-1]-A[i]+1);
                A[i]+=abs(A[i-1]-A[i]+1);
            }
        }
        return cnt;
    }
};
