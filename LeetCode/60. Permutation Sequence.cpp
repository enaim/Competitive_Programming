#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int ar[n+5];
        for(int i=1;i<=n;i++)
            ar[i-1]=i;

        string str;
        int cnt = 0;
        do{
            cnt++;
            if(cnt==k)
            {
                for(int i=0;i<n;i++)
                {
                    char ch = ar[i]+48;
                    str+=ch;
                }
                break;
            }
        }while(next_permutation(ar,ar+n));
        return str;
    }
};
