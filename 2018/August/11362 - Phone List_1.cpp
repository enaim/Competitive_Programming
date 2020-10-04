#include<bits/stdc++.h>
using namespace std;

struct node{
    int cnt,ch[10];
    bool endmark;
    void Clear()
    {
        cnt = 0;
        endmark = false;
        memset(ch,0,sizeof ch);
    }
};
node To[100010];
int state,x;

void add_string(char str[],int len)
{
    int curr = 0;
    for(int i=0;i<len;i++)
    {
        int c = str[i]-'0';

        if(To[curr].ch[c])
            curr = To[curr].ch[c];
        else
        {
            To[curr].ch[c] = ++state;
            To[state].Clear();
            curr = state;
        }
    }
    To[curr].endmark = true;
    To[curr].cnt++;
}

void searchWord(int curr)
{
    for(int i=0;i<10;i++)
    {
        int c;
        if(To[curr].ch[i])
        {
            int temp =  curr;
            if(To[curr].endmark)
                x = 1;
            curr = To[curr].ch[i];
            searchWord(curr);
            curr = temp;
        }
        if(x)
            return;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,n;
    char str[20];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        state = 0;
        To[0].Clear();
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            add_string(str,strlen(str));
        }
        x = 0;
        searchWord(0);
        if(!x)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
