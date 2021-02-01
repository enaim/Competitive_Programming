#include<bits/stdc++.h>
using namespace std;

struct node{
    int length,cnt,ch[26];
    bool endmark;
    void Clear()
    {
        cnt = length = 0;
        endmark = false;
        memset(ch,0,sizeof ch);
    }
};
node To[1000010];
int state;

void add_string(char str[],int len)
{
    int curr = 0;
    for(int i=0;i<len;i++)
    {
        int c = str[i]-'a';
        if(To[curr].ch[c])
            curr = To[curr].ch[c],To[curr].cnt++;
        else
        {
            To[curr].ch[c] = ++state;
            To[state].Clear();
            To[state].length = To[curr].length + 1;
            curr = state;
            To[curr].cnt++;
        }
    }
    To[curr].endmark = true;
}

int searchWord(char str[],int len)
{
    int curr = 0;
    for(int i=0;i<len;i++)
    {
        int c = str[i]-'a';
        if(!To[curr].ch[c])
            return 0;
        curr = To[curr].ch[c];
    }
    return To[curr].cnt;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,q,i;
    char str[110];
    char str1[110];
    int tks;
    state = 0;
    To[0].Clear();
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",str1);
        if(str1[0]=='a')
        {
            scanf("%s",str);
            add_string(str,strlen(str));
        }
        else
        {
            scanf("%s",str);
            cout<<searchWord(str,strlen(str))<<endl;
        }

    }
    return 0;
}
