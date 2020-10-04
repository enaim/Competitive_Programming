#include<bits/stdc++.h>
using namespace std;

char Text[610][610];
char Pattern[2010][2010];
int Prefix[2010][2010];
map<int,int>mp;
vector<int>vec,v;

void Compute_Prefix_Function(int m,int k)
{
    int i,j;
    j = 0;
    Prefix[k][0]=0;
    for(i=1;i<m;i++)
    {
        while((j>0) && (Pattern[k][j] != Pattern[k][i]))
            j = Prefix[k][j-1];

        if(Pattern[k][j] == Pattern[k][i])
            j = j + 1;

        Prefix[k][i]=j;
    }
}

void KMP(int m,int n,int k,int T)
{
    int i,j;
    j = 0;
    for(i=0;i<n;i++)
    {
        while((j>0) && (Pattern[k][j] != Text[T][i]))
            j = Prefix[k][j-1];

        if(Pattern[k][j]==Text[T][i])
        {
            j = j + 1;
            if(j==m)
            {
                vec.push_back(i-m+1);
                j = Prefix[k][j-1];
            }
        }
        else
            j = Prefix[k][j];
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int m,n,i,j,k,l,sz,m1,m2,n1,n2,cnt,x;
    while(2==scanf("%d%d",&m1,&m2))
    {
        x = 0;
        for(i=0;i<m1;i++)
        {
            scanf("%s",Pattern[i]);
            Compute_Prefix_Function(m2,i);
        }

        scanf("%d%d",&n1,&n2);
        for(i=0;i<n1;i++)
            scanf("%s",Text[i]);

        v.clear();
        for(i=0;i<n1-m1+1;i++)
        {
            mp.clear();
            vec.clear();
            KMP(m2,n2,0,i);
            if(vec.size())
            {
                sz = vec.size();
                for(j=0;j<sz;j++)
                    mp[vec[j]]++;
                for(k=1;k<m1;k++)
                {
                    vec.clear();
                    KMP(m2,n2,k,i+k);
                    if(vec.size())
                    {
                        cnt = 0;
                        sz = vec.size();
                        for(l=0;l<sz;l++)
                        {
                            if(mp[vec[l]]==k)
                            {
                                cnt++;
                                if(k==m1-1)
                                    v.push_back(vec[l]);
                                mp[vec[l]]++;
                            }
                        }
                        if(!cnt)
                            break;
                    }
                    if(v.size())
                    {
                        sz = v.size();
                        for(l=0;l<sz;l++)
                        {
                            x = 1;
                            printf("(%d,%d)\n",i+1,v[l]+1);
                        }
                        v.clear();
                    }
                }
            }
        }
        if(!x)
            printf("NO MATCH FOUND...\n");
    }


    return 0;
}
