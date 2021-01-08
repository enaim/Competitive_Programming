

class Solution {
public:
    string getSmallestString(int n, int k) {
        int i,sum=0;
        string str="";
        for(i=0;i<n;i++)
        {
            str+='a';
            sum+=1;
        }
        i = n-1;
        while(sum<k && i>=0)
        {
            int dif = (k-sum);
            if(dif>=25)
            {
                str[i]='z';
                sum+=25;
            }
            else
            {
                str[i]=char('a'+dif);
                sum+=dif;
            }
            i--;
        }
        return str;
    }
};
