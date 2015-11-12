class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        for (int i = A.size() / 2; i >= 0; i--) {
            sink(A, i);
        }
    }
    
    void sink(vector<int> &A, int pos) {
        int leftSonPos = pos * 2 + 1;
        int rightSonPos = pos * 2 + 2;
        
        int leftSon = (leftSonPos >= A.size()) ? INT_MAX : A[leftSonPos];
        int rightSon = (rightSonPos >= A.size()) ? INT_MAX : A[rightSonPos];
        
        if (leftSon < rightSon && leftSon < A[pos]) {
            swap(A[leftSonPos], A[pos]);
            sink(A, leftSonPos);
        } else if (rightSon <= leftSon && rightSon < A[pos]) {
            swap(A[rightSonPos], A[pos]);
            sink(A, rightSonPos);
        }
    }
};
