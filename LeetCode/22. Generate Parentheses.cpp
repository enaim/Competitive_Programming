int depth, NumberOfParenthesis;
string str;
vector<string>vec;
void go(int pos,int first,int second)    ///Pos means current depth
{
    if(pos==depth)
    {
        vec.push_back(str);
        return;
    }
    if(first<NumberOfParenthesis)
    {
        str[pos]='(';
        go(pos+1,first+1,second);
    }
    if(second<NumberOfParenthesis && second<first)
    {
        str[pos]=')';
        go(pos+1,first,second+1);
    }
    return;
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vec.clear();
        depth = n*2;
        str.resize(depth);

        NumberOfParenthesis = n;
        go(0,0,0);
        return vec;
    }
};
