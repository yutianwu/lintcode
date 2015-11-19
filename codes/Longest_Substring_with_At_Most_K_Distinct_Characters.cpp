class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char, int> hash;
        int result = INT_MIN;
        int start = 0, end = 0;
        for (end = 0; end < s.size(); end++) {
            if (hash.find(s[end]) == hash.end()) 
                hash[s[end]] = 0;
            hash[s[end]] += 1;

            while (hash.size() > k) {
                hash[s[start]] -= 1;
                if (hash[s[start]] == 0) 
                    hash.erase(s[start]);
                start++;
            }
            result = max(result, end - start + 1);
        }
        return result == INT_MIN ? 0 : result;
    }
};
