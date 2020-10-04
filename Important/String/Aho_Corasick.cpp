#include<bits/stdc++.h>
using namespace std;


struct node{
    int link,ch[26];
    bitset<510>out;

    void Clear()
    {
        link = 0;
        out.reset();
        memset(ch,0,sizeof ch);
    }
};

node To[250010];
char pattern[510][510],txt[1000010];
int state;
int End[510];

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

void searchWords(int n)
{
    int len = strlen(txt);
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
                {
                    printf("Word %s apperas from %d to %d\n",pattern[j],i - strlen(pattern[j]) + 1,i);
                    End[j]++;
                }
            }
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n;
    while(1==scanf("%s",txt))
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",pattern[i]);

        memset(End,0,sizeof End);
        printf("\n");

        add_string(n);
        buildMatchingMachine();
        searchWords(n);

        printf("\n");
        for(i=0;i<n;i++)
        {
            if(End[i])
                printf("%s found\n",pattern[i]);
            else
                printf("%s not found\n",pattern[i]);
        }

        printf("\n");
        for(i=0;i<n;i++)
            printf("%s occurs %d times\n",pattern[i],End[i]);
    }

    return 0;
}
