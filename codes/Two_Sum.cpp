class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash.insert(make_pair(nums[i], i));
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(target - nums[i]) != hash.end()) {
                result.push_back(i + 1);
                result.push_back(hash[target - nums[i]] + 1);
                break;
            }
        }
        return result;
    }
};
