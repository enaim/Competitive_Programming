#include<bits/stdc++.h>
using namespace std;

vector<int>vec[30];
int p[30],n;

void Clear(int a)
{
    int i,sz,v;
    sz = vec[p[a]].size();
    for(i=sz-1;i>=0;i--)
    {
        v = vec[p[a]][i];
        if(v==a)
            break;
        vec[p[a]].erase(vec[p[a]].begin()+i);
        vec[v].push_back(v);
        p[v]=v;
    }
}

void print()
{
    int i,sz,j;
    for(i=0;i<n;i++)
        {
            printf("%d:",i);
            sz = vec[i].size();
            for(j=0;j<sz;j++)
                printf(" %d",vec[i][j]);
            printf("\n");
        }
}

int main()
{
//    freopen("in.txt","r",stdin);

    char str[100],s1[10],s2[10];
    int i,j,f,v,sz,a,b,x;

    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            vec[i].clear();
            p[i]=i;
            vec[i].push_back(i);
        }
        gets(str);
        while(true)
        {
            gets(str);
            if(strcmp(str,"quit")==0)
                break;
            stringstream ss;
            ss << str;
            ss>>s1>>a>>s2>>b;
            if(strcmp(s1,"move")==0 && strcmp(s2,"onto")==0)
            {
                if(p[a]==p[b])
                    continue;
                Clear(a);
                Clear(b);
                sz = vec[p[a]].size()-1;
                vec[p[a]].erase(vec[p[a]].begin()+sz);
                vec[p[b]].push_back(a);
                p[a]=p[b];
            }
            if(strcmp(s1,"move")==0 && strcmp(s2,"over")==0)
            {
                if(p[a]==p[b])
                    continue;
                Clear(a);
                sz = vec[p[a]].size()-1;
                vec[p[a]].erase(vec[p[a]].begin()+sz);
                vec[p[b]].push_back(a);
                p[a]=p[b];
            }
            if(strcmp(s1,"pile")==0 && strcmp(s2,"onto")==0)
            {
                if(p[a]==p[b])
                    continue;
                Clear(b);
                sz = vec[p[a]].size();
                f = 1;
                x = p[a];
                for(i=0;i<sz;i++)
                {
                    v = vec[x][i];
                    if(f==1 && v!=a)
                        continue;
                    else
                        f = 0;
                    vec[p[b]].push_back(v);
                    p[v]=p[b];
                    vec[x].erase(vec[x].begin() + i);
                    i--;
                    sz--;
                }
            }
            if(strcmp(s1,"pile")==0 && strcmp(s2,"over")==0)
            {
                if(p[a]==p[b])
                    continue;
                sz = vec[p[a]].size();
                f = 1;
                x = p[a];
                for(i=0;i<sz;i++)
                {
                    v = vec[x][i];
                    if(f==1 && v!=a)
                        continue;
                    else
                        f = 0;
                    vec[p[b]].push_back(v);
                    p[v]=p[b];
                    vec[x].erase(vec[x].begin() + i);
                    i--;
                    sz--;
                }
            }
//            print();
        }
        print();
    }

    return 0;
}
