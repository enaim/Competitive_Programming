class Solution {
public:
    string reorderSpaces(string str) {
        int i,j,f;
        int n = str.size();
        int space = 0;
        int word = 0;
        f = 0;
        for(int i=0;i<n;i++)
        {
            if(str[i]==' ')
            {
                space++;
                if(f)
                {
                    f = 0;
                    word++;
                }
            }
            else
                f = 1;
        }
        if(f)
            word++;
        string ans = "";
        if(word==1)
        {
            for(i=0;i<n;i++)
                if(str[i]!=' ')
                    ans+=str[i];
            for(i=0;i<space;i++)
                ans+=" ";
            return ans;
        }
        int equal = space/(word-1);
        int rem = space%(word-1);
        int cnt = word - 1;
        f = 0;
        for(i=0;i<n;i++)
        {
            if(str[i]==' ' && f)
            {
                f = 0;
                if(!cnt)
                    break;
                cnt--;
                for(j=0;j<equal;j++)
                    ans+=" ";
            }
            else if(str[i]!=' ')
            {
                ans+=str[i];
                f = 1;
            }
        }
        for(i=0;i<rem;i++)
            ans+=" ";
        return ans;
    }
};
