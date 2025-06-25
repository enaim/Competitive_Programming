#include<bits/stdc++.h>
using namespace std;


string str1, str2;
int n,m;

int EditDistanceRecursive(int x, int y)
{
    if(x==0)
        return y;
    if(y==0)
        return x;
    if(str1[x-1]==str2[y-1])
        return EditDistanceRecursive(x-1,y-1);
    else
        return 1 + min({EditDistanceRecursive(x,y-1),    ///insert
                       EditDistanceRecursive(x-1,y),    ///remove
                       EditDistanceRecursive(x-1,y-1)}); ///replace
}

int EditDistanceIterative(int n, int m)
{
    int edit[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0)
                edit[i][j]=j;
            else if(j==0)
                edit[i][j]=i;
            else if(str1[i-1]==str2[j-1])
                edit[i][j]=edit[i-1][j-1];
            else
                edit[i][j]= 1 + min({ edit[i][j-1], edit[i-1][j], edit[i-1][j-1]});
        }
    }
    return edit[n][m];
}

int main()
{
    while(cin>>str1>>str2)
    {
        n = str1.size();
        m = str2.size();

        cout<<EditDistanceRecursive(n,m)<<endl;
        cout<<EditDistanceIterative(n,m)<<endl;
    }

    return 0;
}
