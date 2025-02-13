class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            if (num < k) pq.push(num);
        }

        int ans = 0;
        while (!pq.empty()) {
            int fir = pq.top();
            pq.pop();
            ans++;
            if (pq.empty()) break;
            int sec = pq.top();
            pq.pop();
            long long temp = 2LL * fir + sec;
            if (temp < k) pq.push(static_cast<int>(temp));
        }

        return ans;
    }
};
