#include<bits/stdc++.h>
using namespace std;

struct node{
    int length,cnt,ch[26];
    bool endmark,occur;
    void Clear()
    {
        cnt = length = 0;
        endmark = false;
        memset(ch,0,sizeof ch);
    }
};

node To[1000010];
int state,cnt;

void add_string(char str[],int len)
{
    int curr = 0;
    for(int i=0;i<len;i++)
    {
        int c = str[i]-'a';
        if(To[curr].ch[c])
            curr = To[curr].ch[c];
        else
        {
            To[curr].ch[c] = ++state;
            To[state].Clear();
            To[state].length = To[curr].length + 1;
            curr = state;
        }
        To[curr].cnt++;
    }
    To[curr].endmark = true;
}

void searchWord(char str[],int len)
{
    int curr = 0;
    for(int i=0;i<len;i++)
    {
        int c = str[i]-'a';
        if(!To[curr].ch[c])
            return;
        curr = To[curr].ch[c];
    }
    cnt = To[curr].cnt;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,q,i,ks;
    char str[1000010];

    while(2==scanf("%d%d",&n,&q))
    {
        ks = 1;
        state = 0;
        To[0].Clear();

        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            add_string(str,strlen(str));
        }

        while(q--)
        {
            cnt = 0;
            scanf("%s",str);
            searchWord(str,strlen(str));

            printf("%d\n",cnt);
        }
    }

    return 0;
}
