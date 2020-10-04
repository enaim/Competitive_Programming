#include<bits/stdc++.h>
using namespace std;

long long n,i,ar[100010],br[100010],t1[100010],t2[100010],cnt1,cnt2,sum,m,j,mn;
map<long long,long long>mp;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

   while(1==scanf("%lld",&n) && n)
   {
       mp.clear();
       for(i=0;i<n;i++)
       {
           scanf("%lld",&ar[i]);
           mp[ar[i]]++;
       }
       scanf("%lld",&m);
       for(i=0;i<m;i++)
       {
           scanf("%lld",&br[i]);
           mp[br[i]]++;
       }
       cnt1 = cnt2 = sum = 0;
       for(i=0;i<n;i++)
       {
            sum+=ar[i];
            if(mp[ar[i]]==2)
            {
                t1[cnt1++]=sum;
                sum = 0;
            }
       }
       if(sum)
        t1[cnt1++]=sum;
       sum = 0;
       for(i=0;i<m;i++)
       {
            sum+=br[i];
            if(mp[br[i]]==2)
            {
                t2[cnt2++]=sum;
                sum = 0;
            }
       }
       if(sum)
       t2[cnt2++]=sum;
        sum = 0;
        i=0;
        while(i<cnt1 && i<cnt2)
        {
            if(t1[i]<t2[i])
                sum+=t2[i];
            else
                sum+=t1[i];
            i++;
        }
        mn = -1e18;
        mn = max(sum,mn);
        for(j=i;j<cnt1;j++)
            sum+=t1[j];
        for(j=i;j<cnt2;j++)
            sum+=t2[j];

        printf("%lld\n",max(sum,mn));
   }

    return 0;
}
