int srch(vector<int>& arr, int l, int h, int key)
{
    if (l > h) return -1;

    int mid = (l+h)/2;
    if (arr[mid] == key) return mid;
    if (arr[l] <= arr[mid])
    {
        if (key >= arr[l] && key <= arr[mid])
            return srch(arr, l, mid-1, key);
        return srch(arr, mid+1, h, key);
    }

    if (key >= arr[mid] && key <= arr[h])
        return srch(arr, mid+1, h, key);
    return srch(arr, l, mid-1, key);
}

class Solution {
public:
    int search(vector<int>& arr, int key) {
        return srch(arr, 0, arr.size()-1,key);
    }
};
