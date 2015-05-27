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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root == NULL) 
            return 0;
            
        int depthRight = maxDepth(root->right);
        int depthLeft = maxDepth(root->left);
        return max(depthRight, depthLeft) + 1;
    }
};

