class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        vector<int> res(queries.size(), 0);
        if (A.size() == 0) return res;
        
        sort(A.begin(), A.end());
        for (int i = 0; i < queries.size(); i++) {
            res[i] = count(A, queries[i]);
        }
        return res;
    }
    
    int count(vector<int> &A, int query) {
        int size = (int)A.size();
        int lb = -1, ub = size;
        while (ub - lb > 1) {
            int md = lb + (ub - lb) / 2;
            if (A[md] < query) 
                lb = md;
            else 
                ub = md;
        }
        return lb + 1;
    }
};
