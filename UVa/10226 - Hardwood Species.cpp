#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;
const int SIZE = 128;
int n;

struct node{
    bool endmark;
    int cnt=0;
    node* next[SIZE];
    node()
    {
        endmark = false;
        for(int i=0;i<SIZE;i++)
            next[i]=NULL;
    }
}* root;

void _insert(char* str,int len)
{
    node* curr = root;
    for(int i=0;i<len;i++)
    {
        int id = str[i];

        if(curr -> next[id] == NULL)
            curr -> next[id] = new node();
        curr = curr -> next[id];
    }
    curr -> endmark = true;
    curr -> cnt ++;
}

void _count(node *curr,char temp[],int len)
{
    if(curr -> endmark)
    {
        printf("%s ",temp);
        printf("%.4lf\n",(100.0/n)*(curr->cnt));
    }
    for(int i=0;i<SIZE;i++)
    {
        if(curr -> next[i])
        {
            temp[len] = i;
            temp[len+1]='\0';
            _count(curr -> next[i],temp,len+1);
        }
    }
}

void _delete(node* curr)
{
    for(int i=0;i<SIZE;i++)
        if(curr -> next[i])
            _delete(curr -> next[i]);
    delete(curr);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[40],temp[40];
    int i,q,tks,ks=1;
    scanf("%d",&tks);
    gets(str);
    gets(str);
    while(tks--)
    {
        if(ks!=1)
            printf("\n");
        root = new node();

        n = 0;
        while(gets(str))
        {
            if(strlen(str)==0)
                break;
            n++;
            _insert(str,strlen(str));
        }
        temp[0]='\0';
        _count(root,temp,0);
        _delete(root);
        ks++;
    }

    return 0;
}
