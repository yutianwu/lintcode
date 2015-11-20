class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        stack<int> indexStack;
        height.push_back(0);
        int result = INT_MIN;
        for (int i = 0; i < height.size(); i++) {
            while (!indexStack.empty() && height[indexStack.top()] > height[i]) {
                int topIndex = indexStack.top();
                indexStack.pop();
                int frontIndex = indexStack.empty() ? -1 : indexStack.top();
                int area = height[topIndex] * (i - frontIndex - 1);
                result = max(area, result);
            }
            indexStack.push(i);
        }
        return result == INT_MIN ? 0 : result;
    }
};