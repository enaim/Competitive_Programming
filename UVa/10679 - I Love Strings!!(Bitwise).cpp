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

const int MAXS = 100000;

const int MAXC = 52;

int out[MAXS+10];

int f[MAXS+10];

int g[MAXS+10][MAXC+5];

int flag[1010];

int buildMatchingMachine(string arr[], int k)
{
    memset(out, 0, sizeof out);

    memset(g, -1, sizeof g);

    int states = 1;

    for (int i = 0; i < k; ++i)
    {
        const string &word = arr[i];
        int currentState = 0;

        for (int j = 0; j < word.size(); ++j)
        {
            int ch = word[j] - 'a'+26;
            if(word[j]<='Z')
                ch = word[j] - 'A';

            if (g[currentState][ch] == -1)
                g[currentState][ch] = states++;

            currentState = g[currentState][ch];
        }

        out[currentState] |= (1 << i);
    }

    for (int ch = 0; ch < MAXC; ++ch)
        if (g[0][ch] == -1)
            g[0][ch] = 0;

    memset(f, -1, sizeof f);

    queue<int> q;

    for (int ch = 0; ch < MAXC; ++ch)
    {
        if (g[0][ch] != 0)
        {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }

    while (q.size())
    {
        int state = q.front();
        q.pop();

        for (int ch = 0; ch < MAXC; ++ch)
        {
            if (g[state][ch] != -1)
            {
                int failure = f[state];

                while (g[failure][ch] == -1)
                    failure = f[failure];

                failure = g[failure][ch];

                f[g[state][ch]] = failure;

                out[g[state][ch]] |= out[failure];

                q.push(g[state][ch]);
            }
        }
    }

    return states;
}

int findNextState(int currentState, char nextInput)
{
    int answer = currentState;
    int ch = nextInput - 'a'+26;
    if(nextInput<='Z')
        ch = nextInput - 'A';

    while (g[answer][ch] == -1)
        answer = f[answer];

    return g[answer][ch];
}

void searchWords(string arr[], int k, string text)
{
    buildMatchingMachine(arr, k);

    int currentState = 0;

    for (int i = 0; i < text.size(); ++i)
    {
        currentState = findNextState(currentState, text[i]);

        if (out[currentState] == 0)
             continue;

        for (int j = 0; j < k; ++j)
        {
            if (out[currentState] & (1 << j))
            {
                flag[j] = 1;
            }
        }
    }
}

string text,str[1010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,k,i;
    scanf("%d",&tks);
    while(tks--)
    {
        cin>>text;
        memset(flag,0,sizeof flag);
        scanf("%d",&k);
        for(i=0;i<k;i++)
            cin>>str[i];
        searchWords(str, k, text);
        for(i=0;i<k;i++)
        {
            if(flag[i])
                printf("y\n");
            else
                printf("n\n");
        }
    }

    return 0;
}
