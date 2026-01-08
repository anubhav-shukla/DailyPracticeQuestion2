class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int max1 = *max_element(nums1.begin(), nums1.end());
        int min1 = *min_element(nums1.begin(), nums1.end());
        int max2 = *max_element(nums2.begin(), nums2.end());
        int min2 = *min_element(nums2.begin(), nums2.end());
        if (max1 < 0 && min2 > 0) return max1 * min2;
        if (min1 > 0 && max2 < 0) return min1 * max2;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                dp[i][j] = max(nums1[i] * nums2[j] + dp[i + 1][j + 1],
                               max(dp[i + 1][j], dp[i][j + 1]));
            }
        }
        return dp[0][0];
    }
};
