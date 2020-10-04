#include<bits/stdc++.h>
using namespace std;

struct node{
    int cnt,length,ch[4];
    bool endmark;
    void Clear()
    {
        cnt = length = 0;
        endmark = false;
        memset(ch,0,sizeof ch);
    }
};
node To[2000010];
int state,mx;

void add_string(char str[],int len)
{
    int curr = 0;
    for(int i=0;i<len;i++)
    {
        int c;
        if(str[i]=='A')
            c = 0;
        if(str[i]=='C')
            c = 1;
        if(str[i]=='G')
            c = 2;
        if(str[i]=='T')
            c = 3;
        if(To[curr].ch[c])
            curr = To[curr].ch[c];
        else
        {
            To[curr].ch[c] = ++state;
            To[state].Clear();
            To[state].length = To[curr].length+1;
            curr = state;
        }
        To[curr].cnt++;
    }
}

void searchWord(int curr)
{
    for(int i=0;i<4;i++)
    {
        if(To[curr].ch[i])
        {
            int temp = curr;
            curr = To[curr].ch[i];
            mx = max(mx,To[curr].length*To[curr].cnt);
            searchWord(curr);
            curr = temp;
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,q,i,tks,ks=1;
    char str[110];
    scanf("%d",&tks);
    while(tks--)
    {
        mx = 0;
        state = 0;
        To[0].Clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            add_string(str,strlen(str));
        }
        searchWord(0);
        printf("Case %d: %d\n",ks++,mx);
    }
    return 0;
}
