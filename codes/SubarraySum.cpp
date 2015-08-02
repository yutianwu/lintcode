class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        vector<int> result;
        if (nums.size() == 0) return result;
        
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            if (tmp == 0) {
                result.push_back(i);
                result.push_back(i);
                return result;
            }
            
            for(int j = i + 1; j < nums.size(); j++) {
                tmp += nums[j];
                if (tmp == 0) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }      
        return result;
    }
};