#include <bits/stdc++.h>

using namespace std;
stack<char>st;
// Complete the isBalanced function below.
string isBalanced(string str) {
    while(!st.empty())
        st.pop();
    int f = 1,i;
    for(i=0;i<str.size();i++)
    {
         if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            st.push(str[i]);
         else if(!st.empty())
         {
            if(str[i]==')' && st.top()=='(')
            {
                st.pop();
            }
            else if(str[i]=='}' && st.top()=='{')
                st.pop();
            else if(str[i]==']' && st.top()=='[')
                st.pop();
            else
            {
                f = 0;
                break;
            }
         }
         else
         {
            f = 0;
            break;
         }
    }
    if(f && st.empty())
        return "YES";
    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
