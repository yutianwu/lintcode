class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        if (heights.size() <= 1) return 0;
        
        int rightIndx = heights.size() - 1, leftIndx = 0;
        int result = INT_MIN;
        while (leftIndx < rightIndx) {
            int rightHeight = heights[rightIndx], leftHeight = heights[leftIndx];
            int minHeight = min(rightHeight, leftHeight);
            result = max(result, minHeight * (rightIndx - leftIndx));
            if (rightHeight < leftHeight) 
                rightIndx--;
            else 
                leftIndx++;
        }
        return result == INT_MIN ? 0 : result;
    }
};
