#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main()
{
    ll a, b, c, val = 0, ans = 0;
    scanf("%lld %lld %lld", &a, &b, &c);
    ll x = min(a, min(b, c));
    ans += a/3 + b/3 + c/3;
    a%=3;
    b %=3;
    c %=3;
    ll y = min(a, min(b, c));
    ans += y;
    if(a==2)
        ++val;
    if (b==2)
        ++val;
    if(c==2)
        ++val;
    if(val ==2 && x>2)
        ans+=1;
    printf("%lld\n", ans);

    return 0;
}
