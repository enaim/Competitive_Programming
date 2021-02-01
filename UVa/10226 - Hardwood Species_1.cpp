#include<bits/stdc++.h>
using namespace std;

struct node{
    int cnt,ch[128];
    bool endmark;
    void Clear()
    {
        cnt = 0;
        endmark = false;
        memset(ch,0,sizeof ch);
    }
};
node To[300010];
int state,n;

void add_string(char str[],int len)
{
    int curr = 0;
    for(int i=0;i<len;i++)
    {
        int c = str[i];

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

void searchWord(char str[],int len,int curr)
{
    if(To[curr].endmark)
        printf("%s %.4lf\n",str,To[curr].cnt*(100.0/n));

    for(int i=0;i<128;i++)
    {
        int c;
        if(To[curr].ch[i])
        {
            str[len] = i;
            str[len+1] = '\0';
            int temp =  curr;
            curr = To[curr].ch[i];
            searchWord(str,len+1,curr);
            curr = temp;
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    char str[40];
    scanf("%d",&tks);
    gets(str);
    gets(str);
    while(tks--)
    {
        if(ks!=1)
            printf("\n");
        ks++;
        n = 0;
        state = 0;
        To[0].Clear();
        while(gets(str))
        {
            if(strlen(str)==0)
                break;
            add_string(str,strlen(str));
            n++;
        }
        str[0]='\0';
        searchWord(str,0,0);
    }
    return 0;
}
