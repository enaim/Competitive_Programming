int Prefix[100010];
char Pattern[100010];

void Compute_Prefix_Function(int m)
{
    int i,j;
    j = 0;
    Prefix[0]=0;
    for(i=1;i<m;i++)
    {
        while((j>0) && (Pattern[j] != Pattern[i]))
            j = Prefix[j-1];

        if(Pattern[j] == Pattern[i])
            j = j + 1;

        Prefix[i]=j;
    }
}

class Solution {
public:
    string longestPrefix(string s) {
        int i,n = s.size();

        for(i=0;i<n;i++)
            Pattern[i]=s[i];
        Pattern[n]='\0';

        Compute_Prefix_Function(n);

        string temp = "";
        for(int i=0;i<Prefix[n-1];i++)
            temp+=s[i];
        return temp;
    }
};
