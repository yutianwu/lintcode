class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        if (A.size() == 0) return 0;
        
        int asc = 1, desc = 1;
        int result = 1;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1]) 
                asc = asc  + 1;
            else 
                asc = 1;
            if (A[i] < A[i - 1])
                desc = desc + 1;
            else 
                desc = 1;
            result = max(max(asc, desc), result);
        }  
        return result;
    } 
};
