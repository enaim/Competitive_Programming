#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    char str[10][10];
    int n = s.size(),i,j;
    int x = sqrt(n),r,c;
    if(x*x==n)
    {
        r = x;
        c = x;
    }
    else if(x*(x+1)>=n)
    {
        r = x;
        c = x+1;
    }
    else if((x+1)*(x+1)>=n)
    {
        r = x+1;
        c = x+1;
    }
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            str[i][j]='A';
    int cnt = 0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            str[i][j]=s[cnt++];
            if(cnt==n)
                break;
        }
        if(cnt==n)
            break;
    }
    string ans;
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            if(str[j][i]!='A')
                ans+=str[j][i];
        }
        if(i!=c-1)
            ans+=" ";
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
