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
 二叉树的序列化和反序列化，
 这个题目只要自己约定好对二叉树遍历的方法即可，这里使用的是先序遍历
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        if (root == NULL) 
            return "#";
        
        string res = "";
        res += ('0' + root->val);
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        TreeNode *root;
        int pos = 0;
        root = deserialize(data, pos);
        return root;
    }

private:
    TreeNode *deserialize(string &data, int &pos) {
        if (data[pos] == '#') {
            pos++;
            return NULL;
        }
        TreeNode *root = new TreeNode(data[pos] - '0');
        pos++;
        
        root->left = deserialize(data, pos);
        root->right = deserialize(data, pos);
        return root;
    }
};


