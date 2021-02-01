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


struct node{
    bool endmark;
    node* next[26+1];
    node()
    {
        endmark = false;
        for(int i=0;i<26;i++)
            next[i]=NULL;
    }
}* root;

void _insert(char* str,int len)
{
    node* curr = root;
    for(int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if(curr -> next[id] == NULL)
            curr -> next[id] = new node();
        curr = curr -> next[id];
    }
    curr -> endmark = true;
}

bool _search(char* str,int len)
{
    node* curr = root;
    for(int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if(curr -> next[id] == NULL)
            return false;
        curr = curr -> next[id];
    }
    return curr -> endmark;
}

void _delete(node* curr)
{
    for(int i=0;i<26;i++)
        if(curr -> next[i])
            _delete(curr -> next[i]);
    delete(curr);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    while(1==scanf("",&))
    {
        root = new node();
    }

    return 0;
}
