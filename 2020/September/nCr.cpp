#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1000010;
long long fac[SIZE];
long long mod = 998244353;

long long power(long long x, long long y, long long p)
{
    long long res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long modInverse(long long n, long long p)
{
    return power(n, p - 2LL, p);
}

long long nCrModPFermat(long long n,  long long r, long long p)
{
    if (r == 0LL)
        return 1LL;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

void init()
{
    fac[0] = 1LL;
    for (int i = 1; i < SIZE; i++)
        fac[i] = (fac[i - 1] * i) % mod;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    init();

    return 0;
}
