#include<bits/stdc++.h>
using namespace std;

struct node{
    int length,cnt,ch[26];
    bool endmark,print;
    void Clear()
    {
        cnt = length = 0;
        endmark = false;
        memset(ch,0,sizeof ch);
    }
};
node To[500010];
int state,flag;

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

void Dictionary(int curr,char str[],int len)
{
    if(To[curr].endmark)
    {
        flag = 1;
        printf("%s\n",str);
    }

    for(int i=0;i<26;i++)
    {
        if(To[curr].ch[i])
        {
            str[len] = 'a'+i;
            str[len+1]= '\0';
            Dictionary(To[curr].ch[i],str,len+1);
        }
    }
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

    for(int i=0;i<26;i++)
    {
        if(To[curr].ch[i])
        {
            str[len] = 'a'+i;
            str[len+1]= '\0';
            Dictionary(To[curr].ch[i],str,len+1);
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,q,i,ks;
    char str[100010];

    while(1==scanf("%d",&n))
    {
        ks = 1;
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
            printf("Case #%d:\n",ks++);

            flag = 0;
            scanf("%s",str);
            searchWord(str,strlen(str));

            if(!flag)
                printf("No match.\n");
        }
    }

    return 0;
}
