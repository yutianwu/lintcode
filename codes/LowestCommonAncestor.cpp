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


 //解法一

 /*
 解法的思路如下：
    
    使用递归，先判断两个节点A,B是否在以当前节点root为根的二叉树下，
    如果不在，那么没有相同的祖先；
    如果在，那么判断A,B是否同时存在于root节点的左子节点或者又子节点下，如果都不在，说明A,B节点的
    最近祖先就是root，否则递归地判断是root节点的左子节点还是又子节点
 */
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        bool has = false;
        has = findTreeNode(root, A) && findTreeNode(root, B);
        if (!has) return NULL;
        
        bool right, left;
        left = findTreeNode(root->left, A) && findTreeNode(root->left, B);
        right = findTreeNode(root->right, A) && findTreeNode(root->right, B);   
        
        if (!(left || right)) return root;
        if (left) return lowestCommonAncestor(root->left, A, B);
        if (right) return lowestCommonAncestor(root->right, A, B);
    }
    
    bool findTreeNode(TreeNode *now, TreeNode *target) {
        if (now == NULL) return false;

        if (now == target) return true;
        
        return findTreeNode(now->left, target) || findTreeNode(now->right, target);
    }
};


//解法二

/*
这个解法更简单，就是判断A,B节点是否分别存在于当前节点root的左右子树中，如果是，那么返回当前节点，
如果不是，那么总有一个子树包含了两个节点，返回那个值就可以了
*/

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        if (root == NULL) return NULL;
        if (root == A || root == B) return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, A, B);
        TreeNode *right = lowestCommonAncestor(root->right, A, B);
        
        if (left && right) return root;
        
        return left ? left : right;
    }
};



