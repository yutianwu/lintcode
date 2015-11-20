class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int result = INT_MAX;
        int j = 0;
        for (int i = 0; i < A.size(); i++) {
            while (j + 1 < B.size()) {
                if (B[j + 1] > A[i])
                    break;
                j++;
            }
            if (j < B.size()) 
                result = min(result, abs(A[i] - B[j]));
            if (j + 1 < B.size())
                result = min(result, abs(A[i] - B[j + 1]));
        }
        return result;
    }
};