/**
解法一:
    如果将这些柱子里边全注满水，那么，我们看过去将会是一个中间高，两边低的一个塔形，
    就是从两边往中间最高的柱子靠拢，高度不会减小

    所以因为这个特性，我们就可以先求出最高的柱子的位置，然后从从两边往这根柱子搜索，
    因为从两边往中间走，高度不会减小，所以能够存储的水量就是依据两边的柱子的水量来
    定的
**/
class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        int result = 0;
        
        int maxIndx = 0; 
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] > heights[maxIndx])
                maxIndx = i;
        }
        
        int leftHighest = 0;
        for (int i = 0; i < maxIndx; i++) {
            if (heights[i] >= leftHighest) 
                leftHighest = heights[i];
            else 
                result += leftHighest - heights[i];
        }
        
        int rightHighest = 0;
        for (int i = heights.size() - 1; i > maxIndx; i--) {
            if (heights[i] >= rightHighest) 
                rightHighest = heights[i];
            else 
                result += rightHighest - heights[i];
        }
        return result;
    }
};

/**
    解法二：
**/
class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        stack<int> container;
        if (heights.size() == 0) return 0;
        
        int result = 0;
        for (int i = 0; i < heights.size(); i++) {
            int left = 0;
            vector<int> containers;
            while (!container.empty()) {
                int top = container.top();
                
                if (top >=  heights[i]) {
                    left = top;
                    break;
                } else {
                    containers.push_back(top);
                    container.pop();
                }
                left = top;
            }
            
            left = min(heights[i], left);
            for (int j = 0; j < containers.size(); j++) {
                if (left - containers[j] >= 0) {
                    result += left - containers[j];
                    if (heights[i] <= left) {
                        container.push(left);
                    }
                }                
            }
            container.push(heights[i]);
        }
        return result;
    }
};


