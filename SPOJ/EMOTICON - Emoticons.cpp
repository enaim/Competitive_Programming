#include<bits/stdc++.h>
using namespace std;


struct node{
    int link,length,occur,ch[126];
    bitset<110>out;

    void Clear()
    {
        link = length = occur = 0;
        out.reset();
        memset(ch,0,sizeof ch);
    }
};

node To[2010];
char pattern[110][20],txt[90],text[110][90];
int End[110];
int flag[90];
int state,cnt;

struct space{
    int s,e;
};

space ar[10010];

bool compare(space x,space y)
{
    return x.e<y.e;
}

queue<int>Q;

void add_string(int n)
{
    state = 0;
    To[0].Clear();

    for(int i=0;i<n;i++)
    {
        int curr = 0;
        int len = strlen(pattern[i]);
        for(int j=0;j<len;j++)
        {
            int c = pattern[i][j];
            if(To[curr].ch[c])
                curr = To[curr].ch[c];
            else
            {
                To[curr].ch[c] = ++state;
                To[state].Clear();
                To[state].length = To[curr].length+1;
                curr = state;
            }
        }
        End[i]=curr;
        To[End[i]].out.set(i,1);
    }
}

void buildMatchingMachine()
{
    for(int i=0;i<126;i++)
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
        for(int i=0;i<126;i++)
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

void searchWords(int n)
{
    int len = strlen(txt);
    int curr = 0;
    for(int i=0;i<len;i++)
    {
        int c = txt[i];
        curr = To[curr].ch[c];
        To[curr].occur++;

        if(To[curr].out.any())
        {
            for(int j=0;j<n;j++)
            {
                if(To[curr].out.test(j))
                {
                    int sz = strlen(pattern[j]);
                    for(int k=i-sz+1;k<=i;k++)
                        flag[k]++;
                    ar[cnt].s = i-sz+1;
                    ar[cnt].e = i;
                    cnt++;
                }
            }
        }
    }
}

int Replace()
{
    int cnt1 = 0;
    int last = -1;
    for(int i=0;i<cnt;i++)
    {
        if(ar[i].s>last)
        {
            cnt1++;
            last = ar[i].e;
        }
    }
    return cnt1;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,m;
    char ch[10];
    while(2==scanf("%d%d",&n,&m) && n &&m)
    {
        for(i=0;i<n;i++)
            scanf("%s",pattern[i]);
        gets(ch);
        for(i=0;i<m;i++)
            gets(text[i]);

        add_string(n);
        buildMatchingMachine();
        int ans = 0;
        for(i=0;i<m;i++)
        {
            cnt = 0;
            memset(flag,0,sizeof flag);
            strcpy(txt,text[i]);
            searchWords(n);
            ans+=Replace();
        }
        printf("%d\n",ans);
    }

    return 0;
}
