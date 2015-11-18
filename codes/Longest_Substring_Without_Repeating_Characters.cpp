class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        set<char> hash;
        int start = 0, end = 0;
        int result = INT_MIN;
        for (end = 0; end < s.size(); end++) {
            while (hash.find(s[end]) != hash.end()) {
                hash.erase(s[start]);
                start++;
            }
            hash.insert(s[end]);
            result = max(result, end - start + 1);
        }
        return result == INT_MIN ? 0 : result;
    }
};
