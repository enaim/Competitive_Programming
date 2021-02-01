#include<bits/stdc++.h>
using namespace std;
#define mx 1000099
#define ll long long
int pr[1000099],p[100000];
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll t,i,j,x,xx,res,cnt;
    pr[0]=pr[1]=1;
    for(i=4;i<=mx;i+=2)pr[i]=1;
    for(i=3;i<=sqrt(mx);i+=2)
    {
        for(j=i*i;j<=mx;j+=i)pr[j]=1;
    }
    p[0]=2;j=1;
    for(i=3;i<=mx;i+=2)
    {
        if(pr[i]==0)
            p[j++]=i;
    }
    /*while(cin>>t)
    cout<<p[t-1]<<endl;*/
    scanf("%lld",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%lld",&x);
        res=1;j=0;xx=sqrt(x);
        while(xx>=p[j]&&x>=p[j])
        {
            cnt=0;
            while(x%p[j]==0)
            {
                cnt++;
                x/=p[j];
            }
            res*=(cnt+1);j++;
            //printf("        %lld\n",res);
        }
        if(x>1)res*=2;
        printf("Case %d: %lld\n",cas,res);
    }
    return 0;
}
