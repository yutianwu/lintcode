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
/*
二叉树的先序遍历，非递归
*/
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> s;
        if (root == NULL) return res;
        
        s.push(root);
        while(!s.empty()) {
            TreeNode *now = s.top();
            s.pop();
            res.push_back(now->val);
            
            if (now->right != NULL) 
                s.push(now->right);
                
            if (now->left != NULL) 
                s.push(now->left);
        }
        return res;
    }
};