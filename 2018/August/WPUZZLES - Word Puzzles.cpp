#include<bits/stdc++.h>
using namespace std;


struct node{
    int link,length,occur,ch[26];

    bitset<1010>out;

    void Clear()
    {
        link = length = occur = 0;
        out.reset();
        memset(ch,0,sizeof ch);
    }
};
struct ans{
    int row,column,orien;
};

node To[1000010];
char pattern[1010][1010],text[1010][1010],txt[1010];
int End[1010];
ans ar[1010];
int state;
int pat_size[1010];
queue<int>Q;

void add_string(int n)
{
    state = 0;

    To[0].Clear();

    for(int i=0;i<n;i++)
    {
        int curr = 0;
        int len = strlen(pattern[i]);
        pat_size[i]=len;
        for(int j=0;j<len;j++)
        {
            int c = pattern[i][j]-'A';
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
                To[v].out |= To[failure].out;
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

void searchWords(char txt[],int len,int r,int c,int n,int k)
{
    int curr = 0;

    for(int i=0;i<len;i++)
    {
        int C = txt[i]-'A';
        curr = To[curr].ch[C];
        To[curr].occur++;

        if(To[curr].out.any())
        {
            for(int j=0;j<n;j++)
            {
                if(To[curr].out.test(j))
                {
                    ar[j].orien = k;
                    if(k==3)
                    {
                        ar[j].row = r;
                        ar[j].column = i-pat_size[j]+1;
                        break;
                    }
                    if(k==7)
                    {
                        ar[j].row = r;
                        ar[j].column = c-(i-pat_size[j]+1);
                        break;
                    }
                    if(k==5)
                    {
                        ar[j].row = i-pat_size[j]+1;
                        ar[j].column = c;
                        break;
                    }
                    if(k==1)
                    {
                        ar[j].row = r-(i-pat_size[j]+1);
                        ar[j].column = c;
                        break;
                    }
                    if(k==4)
                    {
                        ar[j].row = r+i-pat_size[j]+1;
                        ar[j].column = c+i-pat_size[j]+1;
                        break;
                    }
                    if(k==8)
                    {
                        ar[j].row = r-(i-pat_size[j]+1);
                        ar[j].column = c-(i-pat_size[j]+1);
                        break;
                    }
                    if(k==6)
                    {
                        ar[j].row = r+(i-pat_size[j]+1);
                        ar[j].column = c-(i-pat_size[j]+1);
                        break;
                    }
                    if(k==2)
                    {
                        ar[j].row = r-(i-pat_size[j]+1);
                        ar[j].column = c+(i-pat_size[j]+1);
                        break;
                    }
                }
            }
        }
    }
}

void func(int r,int c,int n)
{
    int i,j,cnt,x;
    for(i=0;i<r;i++)
    {
        strcpy(txt,text[i]);
        searchWords(txt,c,i,0,n,3);
        x = 0;
        while(x<c/2)
        {
            swap(txt[x],txt[c-1-x]);
            x++;
        }
        searchWords(txt,c,i,c-1,n,7);
    }
    for(i=0;i<c;i++)
    {
        cnt = 0;
        for(j=0;j<r;j++)
            txt[cnt++] = text[j][i];
        txt[cnt]='\0';
        searchWords(txt,r,0,i,n,5);
        x = 0;
        while(x<r/2)
        {
            swap(txt[x],txt[r-1-x]);
            x++;
        }
        searchWords(txt,r,r-1,i,n,1);
    }

    for(i=0;i<c;i++)
    {
        cnt = 0;
        for(j=0; j<r && i+j<c ;j++)
            txt[cnt++] = text[j][i+j];
        txt[cnt]='\0';
        searchWords(txt,cnt,0,i,n,4);
        x = 0;
        while(x<cnt/2)
        {
            swap(txt[x],txt[cnt-1-x]);
            x++;
        }
        searchWords(txt,cnt,j-1,i+j-1,n,8);
    }

    for(i=1;i<r;i++)
    {
        cnt = 0;
        for(j=0;i+j<r && j<c ;j++)
            txt[cnt++]= text[i+j][j];
        txt[cnt]='\0';
        searchWords(txt,cnt,i,0,n,4);
        x = 0;
        while(x<cnt/2)
        {
            swap(txt[x],txt[cnt-1-x]);
            x++;
        }
        searchWords(txt,cnt,i+j-1,j-1,n,8);
    }

    for(i=0;i<c;i++)
    {
        cnt = 0;
        for(j=0;j<r && i-j>=0;j++)
            txt[cnt++] = text[j][i-j];
        txt[cnt]='\0';
        searchWords(txt,cnt,0,i,n,6);
        x = 0;
        while(x<cnt/2)
        {
            swap(txt[x],txt[cnt-1-x]);
            x++;
        }
        searchWords(txt,cnt,j-1,i-j+1,n,2);
    }

    for(i=1;i<r;i++)
    {
        cnt = 0;
        for(j=0;i+j<r && c-1-j>=0 ;j++)
            txt[cnt++] = text[i+j][c-1-j];
        txt[cnt]='\0';
        searchWords(txt,cnt,i,c-1,n,6);
        x = 0;
        while(x<cnt/2)
        {
            swap(txt[x],txt[cnt-1-x]);
            x++;
        }
        searchWords(txt,cnt,i+j-1,c-1-j+1,n,2);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,r,c;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d",&r,&c,&n);
        for(i=0;i<r;i++)
            scanf("%s",text[i]);
        for(i=0;i<n;i++)
            scanf("%s",pattern[i]);

        add_string(n);
        buildMatchingMachine();
        func(r,c,n);
        if(ks!=1)
            printf("\n");
        for(i=0;i<n;i++)
            printf("%d %d %c\n",ar[i].row,ar[i].column,ar[i].orien+64);
        ks++;
    }

    return 0;
}
