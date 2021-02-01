class Solution {
public:
    void moveZeroes(vector<int>& ar) {
        int i,j=0,cnt=0;
        for(i=0;i<ar.size();i++)
        {
            if(ar[i]==0)
                cnt++;
            else
                ar[j]=ar[i],j++;
        }
        j = ar.size()-1;
        while(cnt--)
        {
            ar[j]=0;
            j--;
        }
    }
};
