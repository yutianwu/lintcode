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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        travel(root);
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !que.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode *now = que.front();
        que.pop();
        return now;
    }
private:
    queue<TreeNode *> que;
    void travel(TreeNode *root) {
        if (root == NULL) return;
        
        travel(root->left);
        que.push(root);
        travel(root->right);
    }
};

