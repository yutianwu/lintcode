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
 二叉树的中序遍历，非递归
 */
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> s;
        if (root == NULL) return res;
        
        TreeNode *cur = root;
        while (!s.empty() || cur != NULL) {
            if (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            } else {
                TreeNode *now = s.top();
                s.pop();
                res.push_back(now->val);
                cur = now->right;
            }
        }
        return res;
    }
};

