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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    typedef pair<int, int> seg;
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, postorder, make_pair(0, inorder.size() - 1), 
                        make_pair(0, postorder.size() - 1));
    }
private:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, seg in, seg post) {
        if (post.first > post.second) return NULL;
        TreeNode *root = new TreeNode(postorder[post.second]);
        int index = findVal(inorder, postorder[post.second], in);
        root->left = buildTree(inorder, postorder, make_pair(in.first, index - 1), 
                        make_pair(post.first, post.first + index - in.first - 1));
        root->right = buildTree(inorder, postorder, make_pair(index + 1, in.second),
                        make_pair(post.first + index - in.first, post.second - 1));
        return root;        
    }
    
    int findVal(vector<int> &inorder, int val, seg in) {
        for (int i = in.first; i <= in.second; i++) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }
    
};

