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

int z;

struct node{
    bool endmark;
    int vis = 0;
    node* next[10+1];
    node()
    {
        endmark = false;
        for(int i=0;i<11;i++)
            next[i]=NULL;
    }
}* root;

void _insert(char* str,int len)
{
    node* curr = root;
    for(int i=0;i<len;i++)
    {
        int id = str[i]-'0';
        if(curr -> next[id] == NULL)
            curr -> next[id] = new node();
        curr = curr -> next[id];
        if(curr -> endmark == true)
            z  = 1;
        curr -> vis++;
    }
    curr -> endmark = true;
    if(curr -> vis > 1)
        z = 1;
}

void _delete(node* curr)
{
    for(int i=0;i<11;i++)
        if(curr -> next[i])
            _delete(curr -> next[i]);
    delete(curr);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[50];
    int i,n,q,tks;
    scanf("%d",&tks);
    while(tks--)
    {
        z = 0;
        root = new node();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            _insert(str,strlen(str));
        }
        if(z)
            printf("NO\n");
        else
            printf("YES\n");
        _delete(root);
    }

    return 0;
}
