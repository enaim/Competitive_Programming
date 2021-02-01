#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);

    char str[100];
    set<string>st;
    while(1==scanf("%s",str))
        st.insert(str);
    for(auto it:st)
        cout<<it<<endl;

    return 0;
}
