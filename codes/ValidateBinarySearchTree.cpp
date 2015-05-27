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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        int maxval, minval;
        return isValidBST(root, maxval, minval);
    }
    
    bool isValidBST(TreeNode *root, int &maxval, int &minval) {
        if (root == NULL) return true;
        
        if (root->left == NULL) {
            minval = root->val;
        } else {
            int minLeft, maxLeft;
            bool isLeft = isValidBST(root->left, maxLeft, minLeft);
            if (!isLeft) return false;
            if (root->val <= maxLeft) return false;
            minval = minLeft;
        }
        
        if (root->right == NULL) {
            maxval = root->val;
        } else {
            int minRight, maxRight;
            bool isRight = isValidBST(root->right, maxRight, minRight);
            if (!isRight) return false;
            if (root->val >= minRight) return false;
            maxval = maxRight;
        }
        
        return true;
    }
};

