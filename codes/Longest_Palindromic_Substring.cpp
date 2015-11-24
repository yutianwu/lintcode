class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        if (s.size() == 0) return "";
        
        vector<int> p(2 * s.size() + 1, 1);
        int id = 0, mx = 0;
        int maxNum = 0;
        string result = "";
        for (int i = 1; i <= 2 * s.size() - 1; i++) {
            if (mx > i) 
                p[i] = (p[2 * id - i] < (mx -i) ? p[2 * id - i] : (mx - i));
            
            while (i - p[i] >= 0 && i + p[i] <= 2 * s.size() && get(s, i - p[i]) == get(s, i + p[i]))
                p[i]++;

            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
            
            if (p[i] > maxNum) {
                maxNum = p[i];
                result = s.substr((i - p[i] + 1) / 2, p[i] - 1);
            }
        }
        return result;
    }

    char get(string s, int pos) {
        if (pos % 2 == 0)
            return '#';
        else 
            return s[pos / 2];
    }
};
