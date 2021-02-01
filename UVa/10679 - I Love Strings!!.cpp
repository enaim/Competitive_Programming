#include<bits/stdc++.h>
using namespace std;


struct node{
    int link,length,occur,ch[52];

    void Clear()
    {
        link = length = occur = 0;
        memset(ch,0,sizeof ch);
    }
};

node To[9700010];
char pattern[1010][1010],txt[100010];
int End[1010];
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
            int c;
            if(pattern[i][j]<='Z')
                c = pattern[i][j]-'A'+26;
            else
                c = pattern[i][j]-'a';

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
    for(int i=0;i<52;i++)
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

        for(int i=0;i<52;i++)
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
        int c;
        if(txt[i]<='Z')
            c = txt[i]-'A'+26;
        else
            c = txt[i]-'a';
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
        scanf("%s",txt);
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",pattern[i]);

        add_string(n);
        buildMatchingMachine();
        searchWords();

        for(i=0;i<n;i++)
        {
            if(To[End[i]].occur)
                printf("y\n");
            else
                printf("n\n");
        }
    }

    return 0;
}
