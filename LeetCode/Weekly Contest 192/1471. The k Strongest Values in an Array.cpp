struct node{
    int val,dif;
};
node ar[100010];
bool compare(node a,node b)
{
    if(a.dif==b.dif)
        return a.val>b.val;
    return a.dif>b.dif;
}

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int>vec;
        int n = arr.size(),i;
        int m = arr[(n-1)/2];
        for(i=0;i<n;i++)
            ar[i].val = arr[i],ar[i].dif = abs(arr[i]-m);
        sort(&ar[0],&ar[n],compare);
        for(i=0;i<k;i++)
            vec.push_back(ar[i].val);
        return vec;
    }
};
