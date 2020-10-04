#include<bits/stdc++.h>
using namespace std;

#define OO (1<<25)

long long func(int a)
{
    long long x,sum = 0;
    while(a!=0)
    {
        x = a%10;
        a = a/10;
        sum += x*x;
    }
    return sum;
}

int main()
{
    long long a,b,ans,cnt,tem1,tem2;
    map<long long,long long>mp1;
    map<long long,long long>mp2;

    while((scanf("%lld%lld",&a,&b)==2) && a && b)
    {
        tem1 = a;
        tem2 = b;
        mp1.clear();
        mp2.clear();
        cnt = 0;
        while(true)
        {
            if(mp1[a] == 0)
            {
                cnt++;
                mp1[a] = cnt;
            }
            else
                break;

            a = func(a);

        }
        cnt = 0;
        ans = OO;
        while(true)
        {
            if(mp2[b] == 0)
            {
                cnt++;
                mp2[b] = cnt;
                if(mp1[b] != 0)
                {
                    long long x = mp1[b]+mp2[b];
                    if(x<ans)
                        ans = x;
                }
            }
            else
                break;

            b = func(b);

        }
        if(ans == OO)
            printf("%lld %lld 0\n",tem1,tem2);
        else
            printf("%lld %lld %lld\n",tem1,tem2,ans);
    }

    return 0;
}
