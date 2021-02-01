#include<bits/stdc++.h>
using namespace std;


struct node{
    int link,length,occur,ch[26];

    void Clear()
    {
        link = length = occur = 0;
        memset(ch,0,sizeof ch);
    }
};

node To[250010];
char pattern[510][510],txt[1000010];
int End[510];
int state;

queue<int>Q;
pair<int,int>pr[250010];

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
            int c = pattern[i][j]-'a';
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
                To[u].ch[i] = To[ To[u].link ].ch[i];
        }
    }
}

void searchWords()
{
    int len = strlen(txt);
    int curr = 0;

    for(int i=0;i<len;i++)
    {
        int c = txt[i]-'a';
        curr = To[curr].ch[c];
        To[curr].occur++;
    }

    for(int i=0;i<=state;i++)
    {
        pr[i].first = To[i].length;
        pr[i].second = i;
    }

    sort(pr,pr+state+1);

    for(int i=state;i>=0;i--)
        To[ To[pr[i].second].link ].occur += To[pr[i].second].occur;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        scanf("%s",txt);
        for(i=0;i<n;i++)
            scanf("%s",pattern[i]);

        add_string(n);
        buildMatchingMachine();
        searchWords();

        printf("Case %d:\n",ks++);
        for(i=0;i<n;i++)
            printf("%d\n",To[ End[i] ].occur);
    }

    return 0;
}
