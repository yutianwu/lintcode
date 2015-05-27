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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        stack<vector<int> > origin = levelOrder(root);
        vector<vector<int> > res;
        while(!origin.empty()) {
            res.push_back(origin.top());
            origin.pop();
        }
        return res;
    }

    stack<vector<int> > levelOrder(TreeNode *root) {
        stack<vector<int> > res;
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
            res.push(level);
            
            cur = next;
        }
        return res;
    }
};

