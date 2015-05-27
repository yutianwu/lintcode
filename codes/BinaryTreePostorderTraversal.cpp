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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> s;
        if (root == NULL) return res;
        
        s.push(root);
        TreeNode *pre = root;
        while (!s.empty()) {
            TreeNode *now = s.top();
            if ( (pre == now->right || pre == now->left) ||
                    (now->right == NULL && now->left == NULL) ) {
                
                res.push_back(now->val);
                s.pop();
                pre = now;
            } else {
                if (now->right != NULL)
                    s.push(now->right);
                
                if (now->left != NULL) 
                    s.push(now->left);
            }
        }
        return res;
    }
};