#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/// Find all the duplicate strings in an array of strings
/// and divide them into groups
/*
vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}
*/

/// Number of Different substring
/*
int count_unique_substrings(string const& s) {
    int n = s.size();
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}
*/

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

const int p = 31;
const int M = 1e9+9;
//const int MM = 1610612741;

ll h[100010];
ll inv[100010];
ll p_pow[100010];
char str[100010];

void pow_calculate()
{
    p_pow[0]=1;
    for(int i=1;i<100010;i++)
        p_pow[i] = (p_pow[i-1]*p)%M;

    ///inv array is needed for finding substring hash
    inv[0]=1;
    for(int i=1;i<100010;i++)
        inv[i] = BigMod(p_pow[i],M-2,M);
}

void hashing(int n)
{
    h[0]=0;
    for(int i=0;i<n;i++)
        h[i+1] = (h[i]+((str[i]-'a'+1)*p_pow[i]))%M;
}

ll substring_hash(int l,int r)
{
    return (( (h[r+1]-h[l]+M) % M) * (inv[l]%M))%M;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    pow_calculate();
    while(1==scanf("%s",str))
    {
        int n = strlen(str);
        hashing(n);
        printf("Total Hash - > %lld\n",h[n]);
    }

    return 0;
}
