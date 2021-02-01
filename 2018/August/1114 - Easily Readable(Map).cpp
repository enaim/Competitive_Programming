#include<bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    map<string,int>mp;
    int n,m,i,tks,ks=1,ans;
    char st[100010];
    string str;
    scanf("%d",&tks);
    while(tks--)
    {
        mp.clear();
        ans = 1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",st);
            str = st;
            if(str.size()>=4)
                sort(str.begin()+1,str.end()-1);
            mp[str]++;
        }
        printf("Case %d:\n",ks++);
        scanf("%d",&m);
        gets(st);
        for(i=0;i<m;i++)
        {
            ans = 1;
            int x = 0;
            gets(st);
            str=st;
            stringstream ss;
            ss<<str;
            while(ss>>str)
            {
                x = 1;
                if(str.size()>=4)
                    sort(str.begin()+1,str.end()-1);
                ans*=mp[str];
            }
            if(x)
                printf("%d\n",ans);
            else
                printf("1\n");
        }
    }

    return 0;
}
