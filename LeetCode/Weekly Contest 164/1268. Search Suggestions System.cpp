class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int sz = searchWord.size();
        int  n = products.size();
        int i,j=0;
        vector<vector<string>>vec;

        for(i=0;i<sz;i++)
        {
            vector<string>str;
            int cnt = 0;
            for(int k=j;k<n && cnt<3;k++)
            {
                int f = 1;
                int sz1 = products[k].size();
                if(i>=sz1)
                    continue;
                for(int l=0;l<=i && l<sz1;l++)
                    if(products[k][l]!=searchWord[l])
                    {
                        f = 0;
                        break;
                    }
                if(f==0 && cnt>0)
                    break;
                if(f==0)
                    continue;
                if(products[k][i]==searchWord[i])
                    str.push_back(products[k]);
                if(cnt==0)
                {
                    j = k;
                }
                cnt++;
            }
            vec.push_back(str);
        }
        return vec;
    }
};
