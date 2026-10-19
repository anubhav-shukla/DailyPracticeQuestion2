class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>v;
        sort(nums.begin(),nums.end());
        int start = 0 , end = nums.size() - 1;
        int first = -1, last = -1 ;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target)
            {
                first = mid;
                end = mid - 1;
            }
            else if(nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        start = 0 , end = nums.size() - 1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target)
            {
                last = mid;
                start = mid + 1;
            }
            else if(nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        for(int i = first ; i < last ; i++)
            v.push_back(i);
        if(last != -1)
            v.push_back(last);
        return v;
    }
};
