#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'maximumOccurringCharacter' function below.
 *
 * The function is expected to return a CHARACTER.
 * The function accepts STRING text as parameter.
 */

char maximumOccurringCharacter(string text) {
    int i,ind,mx;
    int n = text.size();
    map<char,int>mp;
    for(i=0;i<n;i++)
        mp[text[i]]++;
    mx = ind = -1;
    for(i=0;i<n;i++)
    {
        if(mx<mp[text[i]])
        {
            ind = i;
            mx = mp[text[i]];
        }
    }
    char ans = text[ind];
    return text[ind];
}

int main()
