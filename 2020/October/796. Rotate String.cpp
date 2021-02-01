class Solution {
public:
    bool rotateString(string A, string B) {
        string Add = A + A;
        if(Add.find(B) != -1 && A.size()==B.size())
            return true;
        return false;
    }
};
