class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        if (values.size() == 0) return false;
        
        int size = values.size();
        vector<int> first(size, 0);
        vector<int> second(size, 0);
        first[size - 1] = values[size - 1];
        if (size > 1) 
            first[size - 2] = values[size - 1] + first[size - 2];
        
        for (int i = size - 3; i >= 0; i--) {
            if (values[i] + second[i + 1] > values[i] + values[i + 1] + second[i + 2]) {
                first[i] = values[i] + second[i + 1];
                second[i] = first[i + 1];
            } else {
                first[i] = values[i] + values[i + 1] + second[i + 2];
                second[i] = first[i + 2];
            }
        }
        return first[0] > second[0];
    }
};
