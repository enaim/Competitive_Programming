#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'isPossible' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY calCounts
 *  2. INTEGER requiredCals
 */

vector<long long>vec,vec1;
long long ar[40],k;
int flag,n,mid;

void SubSeqSum(int pos,long long sum)
{
    if(pos==n)
    {
        if(sum==k)
            flag = 1;
        if(sum!=0LL)
            vec1.push_back(sum);
        return;
    }
    SubSeqSum(pos+1,sum+ar[pos]);
    SubSeqSum(pos+1,sum);
    return;
}

void SubSeqSum1(int pos,long long sum)
{
    if(pos==mid+1)
    {
        if(sum==k)
            flag = 1;
        if(sum!=0LL)
            vec.push_back(sum);
        return;
    }
    SubSeqSum(pos+1,sum+ar[pos]);
    SubSeqSum(pos+1,sum);
    return;
}

bool isPossible(vector<int> calCounts, int requiredCals) {
    k = requiredCals;
    flag = 0;
    vec.clear();
    vec1.clear();
    n = calCounts.size();
    for(int i=0;i<n;i++)
        ar[i]=calCounts[i];
    mid = n/2;
    SubSeqSum(mid+1,0);
    SubSeqSum1(0,0);
    if(flag)
        return true;
    n = vec.size();
    int m = vec1.size();
	sort(vec1.begin(),vec1.end());
    for(int i=0;i<n;i++)
    {
        if(k>vec[i])
        {
            long long val = k-vec[i];
            int l = 0;
            int r = m-1;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(vec1[mid]==val)
                    return true;
                if(vec1[mid]<val)
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
    }
    return false;
}

int main()
