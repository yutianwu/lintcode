class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        if (nums.size() < k) return result;
        
        deque<int> window;
        for (int i = 0; i < nums.size(); i++) {
            while (!window.empty()) {
                int back = nums[window.back()];
                if (back <= nums[i]) 
                    window.pop_back();
                else 
                    break;
            }
            window.push_back(i);
            
            if (i - window.front() >= k) 
                window.pop_front();
            
            if (i + 1 >= k) 
                result.push_back(nums[window.front()]);
        }
        
        return result;
    }
};

