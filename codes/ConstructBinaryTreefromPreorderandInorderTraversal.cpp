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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    typedef pair<int, int> seg;
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return buildTree(preorder, inorder, make_pair(0, preorder.size() - 1), 
                    make_pair(0, inorder.size() - 1));
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, seg pre, seg in) {
        if (pre.first > pre.second) return NULL;
        TreeNode *root = new TreeNode(preorder[pre.first]);
        int index = findVal(inorder, preorder[pre.first], in);
        root->left = buildTree(preorder, inorder, make_pair(pre.first + 1, pre.first + index - in.first), 
                        make_pair(in.first, index - 1));
        root->right = buildTree(preorder, inorder, make_pair(pre.first + index - in.first + 1, pre.second), 
                        make_pair(index + 1, in.second));
        return root;        
    }
    
    int findVal(vector<int> &inorder, int val, seg in) {
        for (int i = in.first; i <= in.second; i++) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }
};

