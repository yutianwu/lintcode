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
 使用了双端队列
 */
 

class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > res;
        if (root == NULL) return res;
        queue<TreeNode *> cur;
        cur.push(root);
        bool reverse = false;
        while (!cur.empty()) {
            queue<TreeNode *> next;
            vector<int> level;
            deque<int> tmp;
            while (!cur.empty()) {
                TreeNode *now = cur.front();
                cur.pop();
                
                tmp.push_back(now->val);
                if (now->left) next.push(now->left);
                if (now->right) next.push(now->right);
            }
            
            cur = next;
            while (!tmp.empty()) {
                if (!reverse) {
                    level.push_back(tmp.front());
                    tmp.pop_front();
                } else {
                     level.push_back(tmp.back());
                    tmp.pop_back();                  
                }
            }
            res.push_back(level);
            reverse = !reverse;
        }
    }
};

