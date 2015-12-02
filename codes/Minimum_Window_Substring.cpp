class Solution {
public:
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        int startHis = 0, endHis = 0;
        int start = 0, end = 0;
        int minLength = INT_MAX;
        map<char, int> hash;
        map<char, int> targetHash = initTarget(target);
        for (end = 0; end < source.size(); end++) {
            if (hash.find(source[end]) == hash.end())
                hash[source[end]] = 0;
            hash[source[end]] += 1;
            
            while (isSatisfied(hash, targetHash)) {
                if (end - start + 1 < minLength) {
                    minLength = end - start + 1;
                    startHis = start;
                    endHis = end;
                }
                hash[source[start]] -= 1;
                start++;
            }
        }
        if (minLength == INT_MAX) return "";
        return source.substr(startHis, minLength);
    }

    map<char, int> initTarget(string &target) {
        map<char, int> targetHash;
        for (int i = 0; i < target.size(); i++) {
            if (targetHash.find(target[i]) == targetHash.end())
                targetHash[target[i]] = 0;
            targetHash[target[i]] += 1;
        }
        return targetHash;
    }

    bool isSatisfied(map<char, int> &hash, map<char, int> &target) {
        map<char, int>::iterator it;
        for (it = target.begin(); it != target.end(); it++) {
            if (hash.find(it->first) == hash.end() || hash[it->first] < it->second)
                return false;
        }
        return true;
    }
};
