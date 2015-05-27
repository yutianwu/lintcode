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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        queue<TreeNode *> cur;
        
        if (root == NULL) return res;
        
        cur.push(root);
        while (!cur.empty()) {
            vector<int> level;
            queue<TreeNode *> next;
            while(!cur.empty()) {
                TreeNode *now = cur.front();
                cur.pop();
                
                if (now->left != NULL) 
                    next.push(now->left);
                
                if (now->right != NULL)
                    next.push(now->right);               
                
                level.push_back(now->val);
            }
            res.push_back(level);
            
            cur = next;
        }
        return res;
    }
};