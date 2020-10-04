// Program to calculate C(n ,k)
#include <stdio.h>

// Returns value of Binomial Coefficient C(n, k)
long long binomialCoeff(long long n, long long k)
{
    long long res = 1;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (long long i = 0; i < k; ++i)
    {
    //note: devide first then multiply to avoid overflow, decimal can be taken
    //after every calcualation round up the value
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int main()
{
    //freopen("in", "r", stdin);
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%lld\n", binomialCoeff(2*(n-1), n-1));
    }
    return 0;
}
