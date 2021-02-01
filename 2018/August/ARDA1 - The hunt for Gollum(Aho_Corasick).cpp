#include<bits/stdc++.h>
using namespace std;


struct node{
    int link,ch[26];
    bitset<2010>out;

    void Clear()
    {
        link = 0;
        out.reset();
        memset(ch,0,sizeof ch);
    }
};

node To[100010];
char pattern[2010][2010],txt[610];
int state;

queue<int>Q;
vector<int>v;
map<int,int>mp;
vector<int>vec[2010][610];

void add_string(int n,int len)
{
    state = 0;
    To[0].Clear();

    for(int i=0;i<n;i++)
    {
        int curr = 0;
        for(int j=0;j<len;j++)
        {
            int c = pattern[i][j]-'a';
            if(To[curr].ch[c])
                curr = To[curr].ch[c];
            else
            {
                To[curr].ch[c] = ++state;
                To[state].Clear();
                curr = state;
            }
        }
        To[curr].out.set(i,1);
    }
}

void buildMatchingMachine()
{
    for(int i=0;i<26;i++)
    {
        if(To[0].ch[i])
        {
            int curr = To[0].ch[i];
            Q.push(curr);
            To[i].link = 0;
        }
    }

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int i=0;i<26;i++)
        {
            if(To[u].ch[i])
            {
                int v = To[u].ch[i];
                int failure = To[u].link;

                while(failure && !To[failure].ch[i])
                    failure = To[failure].link;
                To[v].link = To[failure].ch[i];
                Q.push(v);
            }
            else
            {
                 To[u].ch[i] = To[ To[u].link ].ch[i];
                 To[u].out |= To[ To[u].link ].out;
            }
        }
    }
}

void searchWords(int n,int k,int len,int lenp)
{
    int curr = 0;

    for(int i=0;i<len;i++)
    {
        int c = txt[i]-'a';
        curr = To[curr].ch[c];

        if(To[curr].out.any())
        {
            for(int j=0;j<n;j++)
            {
                if(To[curr].out.test(j))
                    vec[j][k].push_back(i - lenp + 1);
            }
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int m1,m2,n1,n2,i,j,k,l,x,sz,cnt;
    while(2==scanf("%d%d",&m1,&m2))
    {
        for(i=0;i<2010;i++)
            for(j=0;j<610;j++)
                vec[i][j].clear();

        for(i=0;i<m1;i++)
            scanf("%s",pattern[i]);

        add_string(m1,m2);
        buildMatchingMachine();

        scanf("%d%d",&n1,&n2);
        for(i=0;i<n1;i++)
        {
            scanf("%s",txt);
            searchWords(m1,i,n2,m2);
        }

        x = 0;
        v.clear();
        for(i=0;i<n1-m1+1;i++)
        {
            mp.clear();
            if(vec[0][i].size())
            {
                sz = vec[0][i].size();
                for(j=0;j<sz;j++)
                    mp[vec[0][i][j]]++;
                for(k=1;k<m1;k++)
                {
                    if(vec[k][k+i].size())
                    {
                        cnt = 0;
                        sz = vec[k][k+i].size();
                        for(l=0;l<sz;l++)
                        {
                            if(mp[vec[k][k+i][l]]==k)
                            {
                                cnt++;
                                if(k==m1-1)
                                    v.push_back(vec[k][k+i][l]);
                                mp[vec[k][k+i][l]]++;
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
