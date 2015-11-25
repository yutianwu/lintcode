class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        if (nums.size() == 0) return 0;
        
        vector<int> K(nums.size(), 0);
        int L = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            int j = find(nums, K, L, i);
            if (j == L || nums[K[j]] > nums[i]) {
                L = max(j + 1, L);
                K[j] = i;
            }
        }
        return L;
    }
    
    int find(vector<int> &nums, vector<int> &K, int L, int pos) {
        int lb = -1, ub = L;
        while (ub - lb > 1) {
            int mid = lb + (ub - lb) / 2;
            if (nums[K[mid]] > nums[pos]) 
                ub = mid;
            else
                lb = mid;
        }
        return ub;
    }
};

