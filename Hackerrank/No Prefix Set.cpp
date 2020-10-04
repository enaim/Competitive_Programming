#include<bits/stdc++.h>
using namespace std;

struct node{
    int length,cnt,ch[10];
    bool endmark;
    void Clear()
    {
        cnt = length = 0;
        endmark = false;
        memset(ch,0,sizeof ch);
    }
};
node To[8000010];
int state;
int f;
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
        if(To[curr].endmark == true)
            f = 1;
    }
    To[curr].endmark = true;
    To[curr].cnt++;
    for(int i=0;i<10;i++)
        if(To[curr].ch[i])
            f = 1;
}

bool searchWord(char str[],int len)
{
    int curr = 0;
    int f = 0;
    for(int i=0;i<len;i++)
    {
        int c = str[i]-'a';
        curr = To[curr].ch[c];
        if(To[curr].endmark==true && i!=len-1)
            return true;
    }
    return false;
}

char str[100010][62];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,q,i;

    int ind;
    while(1==scanf("%d",&n))
    {
        f = 0;
        state = 0;
        To[0].Clear();
        ind = n;
        for(i=0;i<n;i++)
        {
            f = 0;
            scanf("%s",str[i]);
            add_string(str[i],strlen(str[i]));
            if(f)
                ind = min(ind,i);
        }

        if(ind==n)
            printf("GOOD SET\n");
        else
        {
            if(i==n)
                i = ind;
            printf("BAD SET\n");
            printf("%s\n",str[ind]);
        }

    }
    return 0;
}
