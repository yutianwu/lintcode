class MySegmentTreeNode {
public:
    int start, end;
    long long sum;
    MySegmentTreeNode *left, *right;
    MySegmentTreeNode(int start, int end) {
        this->start = start, this->end = end;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /* you may need to use some attributes here */
    MySegmentTreeNode *root = NULL;

    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        root = buildTree(A, 0, A.size() - 1);
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        return query(root, start, end);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        modify(root, index, value);
    }
    
    void modify(MySegmentTreeNode *root, int index, int value) {
        if (root == NULL || root->start > index || root->end < index ) return;
        
        if (root->start == root->end) {
            root->sum = value;
            return;
        }
        int mid =root->start + (root->end - root->start)/2;
        if (index <= mid) 
            modify(root->left, index, value);
        else 
            modify(root->right, index, value);
        
        root->sum = (root->left == NULL ? 0 : root->left->sum) + (root->right == NULL ? 0 : root->right->sum);
    }
    
    long long query(MySegmentTreeNode *root, int start, int end) {
        if (root == NULL) return 0;
        
        if (root->start >= start && root->end <= end) {
            return root->sum;
        }
        return query(root->left, start, end) + query(root->right, start, end);
    }
    
    MySegmentTreeNode *buildTree(vector<int> &A, int start, int end) {
        if (start > end) return NULL;
        
        MySegmentTreeNode *root = new MySegmentTreeNode(start, end);
        if (start == end) {
            root->sum = A[start];
            return root;
        }
        
        int mid = start + (end - start)/2;
        root->left = buildTree(A, start, mid);
        root->right = buildTree(A, mid + 1, end);
        
        root->sum = (root->left == NULL ? 0 : root->left->sum) + (root->right == NULL ? 0 : root->right->sum);
        return root;
    }
};