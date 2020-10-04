#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



using namespace std;
/*
 * Complete the 'kDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER k
 */

int kDifference(vector<int> vec, int k) {
    int n = vec.size();
    sort(vec.begin(),vec.end());
    int cnt,i,j;
    i = j = cnt = 0;
    j++;
    while(j<n)
    {
        if(vec[j]-vec[i]==k)
        {
            cnt++;
            j++;
        }
        else if(vec[j]-vec[i]<k)
            j++;
        else
            i++;
        if(i==j)
            j++;
    }
    return cnt;
}

int main()
