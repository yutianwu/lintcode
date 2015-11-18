class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        if (nums.size() == 0) return -1;
        
        int start = 0, end = 0;
        int result = -1, sum = 0;
        for (end = 0; end < nums.size(); end++) {
            sum += nums[end];
            while (sum >= s) {
                if (result == -1) 
                    result = end - start + 1;
                else {
                    result = min(result, end - start + 1);
                }
                sum -= nums[start];
                start++;
            }
        }
        return result;
    }
};
