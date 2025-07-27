class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int result = 0;
        vector<int> v;
        v.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                v.push_back(nums[i]);
            }
        }
        for (int i = 1; i < v.size() - 1; ++i) {
            if ((v[i] > v[i - 1] && v[i] > v[i + 1]) ||
                (v[i] < v[i - 1] && v[i] < v[i + 1])) {
                result++;
            }
        }
        return result;
    }
};
