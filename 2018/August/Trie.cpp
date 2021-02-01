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
node To[1010];
int state;

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
    }
    To[curr].endmark = true;
    To[curr].cnt++;
}

bool searchWord(char str[],int len)
{
    int curr = 0;
    for(int i=0;i<len;i++)
    {
        int c = str[i]-'a';
        if(!To[curr].ch[c])
            return false;
        curr = To[curr].ch[c];
    }
    return To[curr].endmark;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,q,i;
    char str[110];
    while(1==scanf("%d",&n))
    {
        state = 0;
        To[0].Clear();
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            add_string(str,strlen(str));
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%s",str);
            if(searchWord(str,strlen(str)))
                printf("Found\n");
            else
                printf("Not Found\n");
        }
    }
    return 0;
}
