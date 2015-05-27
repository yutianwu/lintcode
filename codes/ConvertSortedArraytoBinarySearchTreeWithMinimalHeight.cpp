/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        return sortedArrayToBST(A, 0, (int)A.size() - 1);
    }
    
    TreeNode *sortedArrayToBST(vector<int> &A, int begin, int end) {
        if (begin > end) return NULL;
        
        int mid = begin + (end - begin) / 2;
        TreeNode *root = new TreeNode(A[mid]);
        root->left = sortedArrayToBST(A, begin, mid - 1);
        root->right = sortedArrayToBST(A, mid + 1, end);
        return root;
    }
};




