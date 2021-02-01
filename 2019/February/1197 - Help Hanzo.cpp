#include <bits/stdc++.h>
using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

const int FLAG_SIZE = 46400;
const int PRIME_SIZE = 4800;

bool flag[FLAG_SIZE];
ll prime[PRIME_SIZE];

void sieve()
{
    ll i,j,ind = 1,d;
    prime[ind++]=2;

    for(i=3; i<FLAG_SIZE; i+=2)
    {
        if(flag[i] == false)
        {
            prime[ind++]=i;

            if(i > FLAG_SIZE/i)
                continue;

            for(j=i*i,d=i+i; j<=FLAG_SIZE; j+=d)
                flag[j]=true;
        }
    }
}

unordered_set<ll>st;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();

    ll tks,ks=1,i,j,n,a,l,r,sz,odd,even,ans,sq;
    scanf("%lld",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&l,&r);

        n = r-l+1;
        if(n%2==0)
            even=n/2;
        else if(l%2==0)
            even=(n/2) + 1;
        else
            even=n/2;

        odd = n-even;
        st.clear();
        sq = sqrt(r)+1;
        for(i=2; prime[i]<=sq; i++)
        {
            a = (l-1)/prime[i];
            a = (a+1)* prime[i];

            if(a==prime[i])
                a += prime[i];
            if(a%2==0)
                a += prime[i];
            for(j=a; j<=r; j+=(2*prime[i]))
                st.insert(j);
        }
        sz = st.size();

        ans = odd - sz;
        if(l<=2 && 2<=r)
            ans++;
        if(l==1)
            ans--;

        printf("Case %lld: %lld\n",ks++,ans);
    }

    return 0;
}
