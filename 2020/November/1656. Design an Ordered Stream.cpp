class OrderedStream {
public:
    int ptr, N;
    vector<string>vec;
    vector<string>res;
    OrderedStream(int n) {
        res.clear();
        vec.clear();
        vec.resize(n+1);
        ptr = 1;
        N = n;
    }

    vector<string> insert(int id, string value) {
        res.clear();
        vec[id]=value;
        if(id==ptr)
        {
            int i;
            res.push_back(vec[ptr]);
            for(i=ptr+1;i<=N;i++)
            {
                if(vec[i].size()!=0)
                    res.push_back(vec[i]);
                else
                    break;
            }
            ptr = i;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
