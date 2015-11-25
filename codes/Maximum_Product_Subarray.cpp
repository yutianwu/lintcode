class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        int result = 0;
        if (nums.size() == 0) return result;
        int minVal = nums[0], maxVal = nums[0];
        result = max(minVal, maxVal);
        for (int i = 1; i < nums.size(); i++) {
            int mn = minVal, mx = maxVal;
            minVal = min(nums[i], min(nums[i] * mn, nums[i] * mx));
            maxVal = max(nums[i], max(nums[i] * mn, nums[i] * mx));
            result = max(result, maxVal);
        }
        return result;
    }
};
