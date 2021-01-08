class Solution {
public:
    string reformatNumber(string str) {
        int i,n = str.size();
        vector<char>vec;
        for(i=0;i<n;i++)
        {
            if(str[i]>='0' && str[i]<='9')
                vec.push_back(str[i]);
        }
        n = vec.size();
        str="";
        if(n==2)
        {
            str+=vec[0];
            str+=vec[1];
        }
        if(n%3==0)
        {
            for(i=0;i<n-2;i+=3)
            {
                if(i!=0)
                    str+='-';
                str+=vec[i];
                str+=vec[i+1];
                str+=vec[i+2];
            }
        }
        if(n%3==1)
        {
            for(i=0;i<n-6;i+=3)
            {
                if(i!=0)
                    str+='-';
                str+=vec[i];
                str+=vec[i+1];
                str+=vec[i+2];
            }
            if(i!=0)
                str+='-';
            str+=vec[n-4];
            str+=vec[n-3];
            str+='-';
            str+=vec[n-2];
            str+=vec[n-1];
        }
        if(n%3==2 && n!=2)
        {
            for(i=0;i<n-4;i+=3)
            {
                if(i!=0)
                    str+='-';
                str+=vec[i];
                str+=vec[i+1];
                str+=vec[i+2];
            }
            str+='-';
            str+=vec[n-2];
            str+=vec[n-1];
        }
        return str;
    }
};
