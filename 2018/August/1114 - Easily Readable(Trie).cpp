#include<bits/stdc++.h>
using namespace std;

struct node{
    int length,cnt,ch[52];
    bool endmark;
    void Clear()
    {
        cnt = length = 0;
        endmark = false;
        memset(ch,0,sizeof ch);
    }
};
node To[100010];
int state;

void add_string(string str,int len)
{
    int curr = 0;
    for(int i=0;i<len;i++)
    {
        int c = str[i]-'a';
        if(str[i]<='Z')
            c = str[i]-'A'+26;
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

int searchWord(string str,int len)
{
    int curr = 0;
    for(int i=0;i<len;i++)
    {
        int c = str[i]-'a';
        if(str[i]<='Z')
            c = str[i]-'A'+26;
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

    int n,m,i,tks,ks=1,ans;
    char st[100010];
    string str;
    scanf("%d",&tks);
    while(tks--)
    {
        state = 0;
        ans = 1;
        To[0].Clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",st);
            str = st;
            if(str.size()>=4)
                sort(str.begin()+1,str.end()-1);
            add_string(str,str.size());
        }
        printf("Case %d:\n",ks++);
        scanf("%d",&m);
        gets(st);
        for(i=0;i<m;i++)
        {
            ans = 1;
            int x = 0;
            gets(st);
            str=st;
            stringstream ss;
            ss<<str;
            while(ss>>str)
            {
                x = 1;
                if(str.size()>=4)
                    sort(str.begin()+1,str.end()-1);
                ans*=searchWord(str,str.size());
            }
            if(x)
                printf("%d\n",ans);
            else
                printf("1\n");
        }
    }

    return 0;
}
