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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> res;
        travel(root, k1, k2, res);
        return res;
    }
    
    void travel(TreeNode *root, int k1, int k2, vector<int> &res) {
        if (root == NULL) return;
        
        travel(root->left, k1, k2, res);
        if (root->val >= k1 && root->val <= k2) {
            res.push_back(root->val);
        }
        travel(root->right, k1, k2, res);
    }
};

