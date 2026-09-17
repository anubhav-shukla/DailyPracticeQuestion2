class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX / 2);
        int ans = INT_MAX / 2;
        int left = 0, current_sum = 0;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];

            while (current_sum > target) {
                current_sum -= arr[left++];
            }

            if (right > 0) {
                min_len[right] = min_len[right - 1];
            }

            if (current_sum == target) {
                int curr_len = right - left + 1;
                if (left > 0 && min_len[left - 1] < INT_MAX / 2) {
                    ans = min(ans, min_len[left - 1] + curr_len);
                }
                min_len[right] = min(min_len[right], curr_len);
            }
        }

        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};
