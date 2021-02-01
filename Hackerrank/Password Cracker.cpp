#include<bits/stdc++.h>
using namespace std;


struct node{
    int link,ch[26];
    bitset<20>out;

    void Clear()
    {
        link = 0;
        out.reset();
        memset(ch,0,sizeof ch);
    }
};

struct coord{
    int x,y,ind;
};
coord ar[100000];
node To[250010];
char pattern[20][20],txt[2010];
int state;
int cnt1;
int End[510];
int ks=1;
queue<int>Q;
vector<int>vec;

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
                    coord z;
                    z.x = i - strlen(pattern[j]) + 1;
                    z.y = i;
                    z.ind = j;
                    ar[cnt1++]=z;
                    End[j]++;
                }
            }
        }
    }
}

bool compare(coord a,coord b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int dp[50000][2100];
int f,sz;
int go(int pos,int len)
{
    if(len==sz-1)
        return 1;
    if(len>=sz || pos>=cnt1)
        return 0;
    int &re = dp[pos][len];
    if(re!=-1)
        return re;
    re = 0;
    for(int i=pos;i<cnt1;i++)
    {
        if(ar[i].x==len+1)
        {
            re = go(i+1,ar[i].y);
            if(re==1)
            {
                vec.push_back(ar[i].ind);
                return re;
            }
        }
    }
    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n;
    int tks;
    scanf("%d",&tks);
    while(tks--)
    {
        vec.clear();
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",pattern[i]);
        scanf("%s",txt);
        sz = strlen(txt);
        memset(End,0,sizeof End);
        cnt1 = 0;
        add_string(n);
        buildMatchingMachine();
        searchWords(n);

        sort(&ar[0],&ar[cnt1],compare);
        for(i=0;i<cnt1;i++)
            if(ar[i].x==0)
            {
                f = 0;
                f = go(i+1,ar[i].y);
                if(f==1)
                {
                    vec.push_back(ar[i].ind);
                    break;
                }
            }
        reverse(vec.begin(),vec.end());
        if(vec.size())
        {
            for(i=0;i<vec.size();i++)
            {
                if(i==0)
                    printf("%s",pattern[vec[i]]);
                else
                    printf(" %s",pattern[vec[i]]);
            }
            printf("\n");
        }
        else
        {
            printf("WRONG PASSWORD\n");
        }
    }

    return 0;
}
