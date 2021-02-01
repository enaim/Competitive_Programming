#include<iostream>
using namespace std;
int G[200][200],indeg[200],flag[200];
int main()
{
    int n,m,i,j,k,u,v,cnt=0;
    while(cin>>n>>m)
    {
        if(n==0 &&m==0)break;
        cnt=0;
        for(i=0;i<=110;i++)
        {
            indeg[i]=flag[i]=0;
            for(j=0;j<=110;j++)G[i][j]=0;
        }

        for(i=1; i<=m; i++)
        {
            cin>>u>>v;
            G[u][v]=1;
            indeg[v]++;
        }
        //cout<<"Top Sort Order is: ";
        while(cnt<n)
        {
            for(k=1; k<=n; k++)
            {
                if(indeg[k]==0 && flag[k]==0)
                {
                    flag[k]=1;
                    cout<<k;
                    cnt++;
                    if(cnt<n)cout<<" ";
                    for(i=1; i<=n; i++)
                    {
                        if(G[k][i])indeg[i]--;
                    }
                }
            }
        }
        cout<<endl;
    }
}
