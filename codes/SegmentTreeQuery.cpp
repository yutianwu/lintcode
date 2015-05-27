/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        if (root == NULL) return -1;
        int k_start = root->start, k_end = root->end;
        
        if (start <= k_start && end >= k_end) return root->max;
        int mid = k_start + (k_end - k_start)/2;
        if (end <= mid) {
            int max_left = query(root->left, start, end);
            return max_left;
        } else if (start <= mid && end > mid) {
            int max_left = query(root->left, start, mid);
            int max_right = query(root->right, mid + 1, end);
            return max(max_left, max_right);
        } else {
            int max_right = query(root->right, start, end);
            return max_right;
        }
    }
};

