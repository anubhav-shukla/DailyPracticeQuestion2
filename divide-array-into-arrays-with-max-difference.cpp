class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // min-heap, putting elements in heap
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        vector<vector<int>> res;

        while (pq.size() >= 3) {
            int low = pq.top(); pq.pop();
            int mid = pq.top(); pq.pop();
            int great = pq.top(); pq.pop();

            if (great - low <= k) {
                res.push_back({low, mid, great});
            } 
            else {
                return {}; // Cannot group
            }
        }
        return res;
    }
};
