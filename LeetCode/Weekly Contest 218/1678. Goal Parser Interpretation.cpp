class Solution {
public:
    string interpret(string str) {
        string s = "";
        int n = str.size();
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='G')
                s+="G";
            else if(i+1<n && str[i]=='(' && str[i+1]==')')
                s+="o",i++;
            else if(i+3<n && str[i]=='(' && str[i+1]=='a' && str[i+2]=='l' && str[i+3]==')')
                s+="al",i+=3;
        }
        return s;
    }
};
