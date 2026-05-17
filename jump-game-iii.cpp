class Solution {
public:
    bool f(int i, int n, vector<int>& arr) {
        if (arr[i] == 0)
            return true;
        if (arr[i] == -1)
            return false;
        int d = arr[i];
        arr[i] = -1;
        return (i - d >= 0 and f(i - d, n, arr)) ||
               (i + d < n and f(i + d, n, arr));
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        return f(start, n, arr);
    }
};
