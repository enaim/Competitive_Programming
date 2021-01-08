class Solution {
public:
    int minPartitions(string n) {
        sort(n.begin(),n.end());
        return n[n.size()-1]-'0';
    }
};
