/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

class MinTreeNode {
public:
    int start, end;
    int min;
    MinTreeNode *left, *right;
    MinTreeNode(int start, int end) {
        this->start = start, this->end = end;
        this->left = this->right = NULL;
    }
};



class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<int> result;
        if (A.size() == 0) return result;
         MinTreeNode *root = buildTree(A, 0, A.size() - 1);
         for (int i = 0; i < queries.size(); i++) {
            int tmp = query(root, queries[i].start,  queries[i].end);
            result.push_back(tmp);
         }
         return result;
    }
    
    MinTreeNode *buildTree(vector<int> &A, int start, int end) {
        if (start > end)  return NULL;
        
        MinTreeNode *root = new MinTreeNode(start, end);
        if (start == end) {
            root->min = A[start];
            return root;
        }
        int mid = start + (end - start)/2;
        root->left = buildTree(A, start, mid);
        root->right = buildTree(A, mid + 1, end);
        
        root->min = min( (root->left == NULL ? INT_MAX : root->left->min), 
                            (root->right == NULL ? INT_MAX : root->right->min) );
        return root;
    }
    
    int query(MinTreeNode *root, int start, int end) {
        if (root == NULL) return INT_MAX;
        
        if (root->start >= start && root->end <= end) {
            return root->min;
        }
        return min(query(root->left, start, end), query(root->right, start, end));
    }
};


